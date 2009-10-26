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

#ifndef ALIEN_H
#define ALIEN_H

#include <tgalaxy.h>
#include <projectile.h>
#include <gameobj.h>
#include <messagetypes.h>
#include <world.h>
#include <statemachine.h>
#include <state.h>

extern const int ALIEN_ROWS;
extern const int ALIEN_WIDTH;
extern const int ALIEN_HEIGHT;
extern const int ALIENS_IN_ROW;
extern const float ALIEN_FIRING_RATE;
extern const int ALIEN_MAXIMUM_SHOTS;
extern const int DEFAULT_ALIEN_ENERGY;
extern const int ALIEN_OFFSET;
extern const int ALIEN_SPACING;

enum ALIEN_DIRECTION {
	RIGHT = 1,
	LEFT = -1
};

class Alien : public GameObj {
	private:
		GameWorld *world;
		int maximum_shots;
		int current_shots;
		int direction;
		int energy;
		StateMachine<Alien> *state_machine;
		double etime;
		int c, r;
		double accumulated_time;
		int current_animation_frame;

		inline int row_to_y(int row) {
			return WORLD_HEIGHT - (ALIEN_OFFSET + row * (ALIEN_SPACING + ALIEN_HEIGHT));
		}

		inline int col_to_x(int col) {
			return ALIEN_OFFSET + col * (ALIEN_SPACING + ALIEN_WIDTH);
		}

		void swap_direction() {
			if(direction == RIGHT) {
				direction = LEFT;
			}
			else {
				direction = RIGHT;
			}
		}

		friend class SquadState;
		friend class DescentState;

	public:
		Alien(int row, int col, GameWorld *w);

		~Alien() {
			delete state_machine;
		}

		void update(double);

		void draw();

		void print();

		bool handle_message(const Telegram &msg);

		void destroy_mankind() {
			world->game_over();
		}

		void shoot();

		int current_energy() {
			return energy;
		}

		friend class ExplosionState;
};

#endif

