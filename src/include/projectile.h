// Copyright (c) 2009-2010, Renato Cunha
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

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <tgalaxy.h>
#include <world.h>
#include <gameobj.h>
#include <entitymanager.h>
#include <dispatcher.h>
#include <telegram.h>
#include <messagetypes.h>

extern const int PROJECTILE_WIDTH;
extern const int PROJECTILE_HEIGHT;
extern const int PROJECTILE_VELOCITY_X;
extern const int PROJECTILE_VELOCITY_Y;

class Projectile : public GameObj {
	private:
		int shooter;
		int shooter_id;
		GameWorld *world;
	public:
		Projectile(int px,
				int py,
				int heading,
				int shooter_type,
				int shooter_id_,
				GameWorld *game_world
				) : GameObj(PROJECTILE_TYPE, px, py,
					heading2x[heading] * PROJECTILE_VELOCITY_X,
					heading2y[heading] * PROJECTILE_VELOCITY_Y,
					PROJECTILE_WIDTH,
					PROJECTILE_HEIGHT)
		{
			if(shooter_type != DEFENDER_TYPE && shooter_type != ALIEN_TYPE) {
				DebugPrint("Shooter type %d not supported" _C_ shooter_type);
			}
			shooter = shooter_type;
			Assert(game_world);
			world = game_world;
			shooter_id = shooter_id_;
		}

		~Projectile();

		void update(double elapsed_time);

		void draw();

		void print();

};

#endif

