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

#ifndef GAME_H
#define GAME_H

#include <tgalaxy.h>

class Printer;
class GameWorld;

class Game {
	private:
		bool debug;
		Printer *printer;
		GameWorld *world;
		int current_outcome;
		unsigned int aliens;
		unsigned long long step;
		unsigned long long score;
		void draw_velocity_bar();

		void draw_score();
		void draw_outcome();
		void draw_energy(int energy);

		void create_gl_window(int, int, int, int);

	public:
		friend class GameWorld;

		void run();
		void draw_game();
		Game(int argc, char **argv);

		void outcome(int o) {
			DebugPrint("Setting outcome to %d.\n" _C_ o);
			current_outcome = o;
		}

		~Game() {
			DebugPrint("Deallocating game...\n");
		}

		void process_mouse(const SDL_Event &event);
		void process_reshape(const SDL_Event &event);
		void process_keyboard(const SDL_Event &event);
		void process_mouse_motion(const SDL_Event &event);

		void update_game();
		void draw_interface();

		bool dead_zone(int x) {
			if(x >= WINDOW_CENTER_X - 5 && x <= WINDOW_CENTER_X + 5) {
				return true;
			}
			return false;
		}

		bool lock_fps(double frame_duration) {
			static double last_time = 0.0f;

			double current_time = double_timeofday();

			if((current_time - last_time) > frame_duration)
			{
				last_time = current_time;
				return true;
			}

			return false;
		}

};

#endif

