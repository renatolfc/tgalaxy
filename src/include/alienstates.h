// Copyright (c) 2009, Renato Cunha 
// All rights reserved. 
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are 
// met: 
// 
//  * Redistributions of source code must retain the above copyright notice, 
//    this list of conditions and the following disclaimer. 
//  * Redistributions in binary form must reproduce the above copyright 
//    notice, this list of conditions and the following disclaimer in the 
//    documentation and/or other materials provided with the distribution. 
//  * Neither the name of  nor the names of its contributors may be used to 
//    endorse or promote products derived from this software without 
//    specific prior written permission. 
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS 
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR 
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 

#ifndef ALIENSTATES_H
#define ALIENSTATES_H
#include <cstdlib>

#include <tgalaxy.h>
#include <statemachine.h>
#include <state.h>
#include <gameobj.h>
#include <alien.h>
#include <telegram.h>
#include <dispatcher.h>
#include <world.h>
#include <alien_image.h>
#include <explosion.h>

class SquadState;
class ExplosionState;
const int ALIEN_ANIMATION_FRAMES = 3;

extern SquadState alien_squad_state;
extern ExplosionState alien_explosion_state;

class ExplosionState : public State<Alien> {

	void enter(Alien *owner) {
		owner->accumulated_time = 0;
	}

	void execute(Alien *owner){

		if(owner->accumulated_time > 1) {
			entities.destroy_entity(owner);
			return;
		}

		owner->current_animation_frame = (int)(owner->accumulated_time / 0.14285714285714285);

		if(owner->current_animation_frame > 6) {
			entities.destroy_entity(owner);
			return;
		}

	}

	bool on_message(Alien *alien, const Telegram &msg) {
		return false;
	}

	void exit(Alien *owner) {
	}

	void draw(Alien *owner) {
		glPixelZoom(1.0, -1.0);
		glRasterPos2d(owner->x - 4, owner->y - 4);
		glDrawPixels(explosion_image.width, explosion_image.height,
				explosion_image.bytes_per_pixel == 3 ? GL_RGB : GL_RGBA,
				GL_UNSIGNED_BYTE, explosion_image.pixel_data[owner->current_animation_frame]);
		glPixelZoom(1.0, 1.0);
	}

};

class SquadState : public State<Alien> {

	void enter(Alien *owner) {
	}

	void execute(Alien *owner){
		int w, h, r;
		int width, height;
		double x, y, time;

		x = owner->x;
		y = owner->y;
		w = owner->w;
		h = owner->h;
		r = owner->r;
		time = owner->etime;

		owner->world->dimensions(width, height);

		double new_x, new_y;

		new_x = x + (owner->vel_x * time * owner->direction);
		new_y = owner->vel_y * time + y;

		owner->x = new_x;
		owner->y = new_y;

		if((new_x + w) > width || new_x < 0) {
			int *info = new int(r);
			dispatcher.broadcast(0, owner->id(), ALIEN_TYPE, MSG_SWAP_DIRECTION, info);
			delete info;
			if(new_x < 0) {
				owner->x = 0;
			}
			else {
				owner->x = width - w;
			}
		}

		if(new_y - h - VELOCITY_BAR_HEIGHT < 0) { // History ends...
			dispatcher.broadcast(0, owner->id(), RECEIVER_TYPE_IRRELEVANT,
					MSG_ALIEN_GOT_TO_EARTH);
		}

		if((double)random() / (double)RAND_MAX < ALIEN_FIRING_RATE) { //fire!
			owner->shoot();
		}

		owner->current_animation_frame = ((int)owner->accumulated_time) % ALIEN_ANIMATION_FRAMES;
	}

	bool on_message(Alien *owner, const Telegram &msg) {
		switch(msg.msg)
		{
			case MSG_SWAP_DIRECTION:
				int row; 
				row = dereference_to_type<int>(msg.extra_info);

				if(owner->r == row) {
					owner->swap_direction();
				}

				DebugPrint("Swapping Direction on row %d\n" _C_ row);

				return true;

			case MSG_BEEN_HIT:
				owner->energy--;
				if(owner->energy <= 0) {
					owner->state_machine->change_state(&alien_explosion_state);
					dispatcher.broadcast(0, owner->id(), RECEIVER_TYPE_IRRELEVANT,
							MSG_ALIEN_DESTROYED);
				}
				return true;

			default:
				return true;
		}

		return false;
	}

	void exit(Alien *owner) {
	}

	void draw(Alien *owner) {
		glPixelZoom(1.0, -1.0);
		glRasterPos2d(owner->x, owner->y);
		glDrawPixels(alien_image.width, alien_image.height,
				alien_image.bytes_per_pixel == 3 ? GL_RGB : GL_RGBA,
				GL_UNSIGNED_BYTE, alien_image.pixel_data[owner->current_animation_frame]);
		glPixelZoom(1.0, 1.0);
	}
};

class DescentState : public State<Alien> {

	void enter(Alien *owner) {
	}

	void execute(State<Alien> *owner){
	}

	bool on_message(Alien *alien, const Telegram &msg) {
		return false;
	}

	void exit(Alien *owner) {
	}

};

#endif

