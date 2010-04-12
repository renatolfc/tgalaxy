// Copyright (c) 2009-2010, Renato Cunha 
// All rights reserved. 
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are 
// met: 
// 
//	* Redistributions of source code must retain the above copyright notice, 
//	  this list of conditions and the following disclaimer. 
//	* Redistributions in binary form must reproduce the above copyright 
//	  notice, this list of conditions and the following disclaimer in the 
//	  documentation and/or other materials provided with the distribution. 
//	* Neither the name of  nor the names of its contributors may be used to 
//	  endorse or promote products derived from this software without 
//	  specific prior written permission. 
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

#include <sys/time.h>
#include <map>
#include <vector>

#include <tgalaxy.h>
#include <world.h>
#include <alien.h>
#include <defender.h>
#include <game.h>
#include <star.h>

void GameWorld::game_over() {
	endgame = true;
	if(player_succeeded) {
		game->outcome(OUTCOME_SUCCESS);
	}
	else {
		game->outcome(OUTCOME_FAILURE);
	}
}

void GameWorld::setup_game() {

	defender = new Defender(width / 2 - DEFENDER_WIDTH / 2,
				VELOCITY_BAR_HEIGHT + 5 + DEFENDER_HEIGHT, this);

	int nstars = 30;
	endgame = false;
	remaining_aliens = 0;
	earth_destroyed = false;
	player_succeeded = false;
	defender_destroyed = false;
	dispatcher.subscribe_game(this);
	game->outcome(OUTCOME_NOT_DEFINED);
	entities.register_entity(defender);

	for(int i = 0; i < nstars; i++) {
		stars.push_back(
				new Star((int)WINDOW_WIDTH * ((float)random()/(float)RAND_MAX),
					(int)WINDOW_HEIGHT * ((float)random()/(float)RAND_MAX)));
	}

	for(int i = 0; i < ALIEN_ROWS; i++) { // Aliens
		for(int j = 0; j < ALIENS_IN_ROW; j++) {
			entities.register_entity(new Alien(i, j, this));
			remaining_aliens++;
		}
	}
}

void GameWorld::handle_message(int msg, int sender, int receiver_type,
		void *extra_info) {
	switch(msg) {
		case MSG_DEFENDER_HIT:
			break;
		case MSG_DEFENDER_DESTROYED:
			DebugPrint("Defender destroyed. Game Over.\n");
			defender_destroyed = true;
			game_over();
			break;
		case MSG_ALIEN_GOT_TO_EARTH:
			DebugPrint("Alien got to Earth. Game Over.\n");
			earth_destroyed = true;
			game_over();
			break;
		case MSG_ALIEN_DESTROYED:
			DebugPrint("Alien destroyed. Reducing count.\n");
			remaining_aliens--;
			game->score += ALIEN_DESTRUCTION_POINTS * defender->current_energy();
			if(remaining_aliens > 0) {
				break;
			}
			DebugPrint("Player Succeeded. Game Over.\n");
			player_succeeded = true;
			game_over();
	}
}

GameWorld::GameWorld(int w, int h, Game *g) :
	width(w),
	height(h),
	paused(false),
	game_finished(false),
	mouse_x(0), mouse_y(0),
	game(g)
{
	DebugPrint("Creating a new world...\n");

	start_time = double_timeofday();
	last_frame = double_timeofday();
	current_frame = double_timeofday();

	elapsed_time = 0;

	setup_game();
}

void GameWorld::toggle_pause() {
	paused = !paused;
}

void GameWorld::pause() {
	paused = true;
}

void GameWorld::update_simulation() {

	last_frame = current_frame;
	current_frame = double_timeofday();

	elapsed_time = current_frame - last_frame;

	if(!endgame) {
		if(!paused) {
			entities.update_all(elapsed_time);
		}
	}
}

void GameWorld::draw() {
	entities.draw_all();
	glBlendFunc(GL_ZERO, GL_ZERO);
	for(unsigned int i = 0; i < stars.size(); i++) {
		stars[i]->draw();
	}
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
}

void GameWorld::print() {
	entities.print_all();
}

void GameWorld::destroy_game() {
	defender = NULL;
	entities.destroy_all();
	stars.clear();
}

void GameWorld::restart() {
	destroy_game();
	setup_game();
	paused = false;
}

void GameWorld::defender_speed(int vx) {
	defender->set_speed(vx);
}

void GameWorld::defender_shoot() {
	if(!paused) {
		defender->shoot();
	}
}

void GameWorld::mouse_position(int x, int y) {
	if(!paused) {
		mouse_x = x;
		mouse_y = y;
	}
}

