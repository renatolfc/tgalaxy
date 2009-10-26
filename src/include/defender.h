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

#ifndef DEFENDER_H
#define DEFENDER_H

#include <world.h>
#include <gameobj.h>

extern const int DEFENDER_WIDTH;
extern const int DEFENDER_HEIGHT;
extern const int DEFENDER_MAX_SPEED;
extern const int DEFENDER_MAXIMUM_SHOTS;
extern const int DEFENDER_DEFAULT_ENERGY;

class Defender : public GameObj {
	private:
		GameWorld *world;
		int maximum_shots;
		int current_shots;
		int energy;

	public:
		Defender(int initial_x, int initial_y, GameWorld *game_world) :
			GameObj(DEFENDER_TYPE,
					initial_x,
					initial_y,
					0,
					0,
					DEFENDER_WIDTH,
					DEFENDER_HEIGHT),
			maximum_shots(DEFENDER_MAXIMUM_SHOTS),
			current_shots(0),
			energy(DEFENDER_DEFAULT_ENERGY)
		{
			Assert(game_world);
			world = game_world;
		}

		~Defender() {
		}

		void update(double elapsed_time);

		void draw();

		void print();

		void shoot();

		bool handle_message(const Telegram &msg);

		void increase_maximum_shots(unsigned int offset) {
			DebugPrint("Increasing maximum shots by %d" _C_ offset);
			maximum_shots += offset;
		}

		void offset_shots(int offset) {
			DebugPrint("Offseting current shots by %d" _C_ offset);
			current_shots += offset;
		}

		void set_speed(int vx);

		int current_energy() {
			return energy;
		}
};

#endif

