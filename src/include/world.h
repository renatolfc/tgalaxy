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

#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <sys/time.h>
#include <tgalaxy.h>

class Game;
class Star;
class Alien;
class Defender;

class GameWorld {
	public:
		friend class Alien;

	private:
		int width;
		int height;
		bool paused;
		bool game_finished;
		Defender *defender;

		double start_time;
		double last_frame;
		double current_frame;

		double elapsed_time;

		int mouse_x, mouse_y;

		Game *game;

		void game_over();

		void destroy_game();

		bool defender_destroyed;

		int remaining_aliens;

		bool player_succeeded;

		bool earth_destroyed;

		bool endgame;

		std::vector<Star *> stars;

	public:
		friend class Game;

		void dimensions(int &w, int &h) {
			w = width;
			h = height;
		}

		bool is_paused() {
			return paused;
		}

		GameWorld(int w, int h, Game *g);

		void setup_game();

		void toggle_pause();

		void pause();

		void update_simulation();

		void draw();

		void print();

		void restart();

		void defender_speed(int vx);

		void defender_shoot();

		void mouse_position(int x, int y);

		void handle_message(int message, int sender, int receiver_type,
				void *extra_info);

};

#endif

