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

#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include <vector>

class Telegram;

enum GAMEOBJ_TYPES {
	PROJECTILE_TYPE = 0,
	DEFENDER_TYPE = 1,
	ALIEN_TYPE = 2,
	STAR_TYPE = 3
};

class GameObj {
	friend class EntityManager;

	protected:
		int id;

		int type;

		double x, y; // left top
		int vel_x, vel_y;
		int w, h; // width, height

	private:

		int next_valid_id() {
			static int next_id = 0;
			return next_id++;
		}

	public:

		GameObj(int type,
				int px = 0,
				int py = 0,
				int vx = 0,
				int vy = 0,
				int width = 32,
				int height = 32) :
			id(next_valid_id()),
			type(type),
			x(px),
			y(py),
			vel_x(vx),
			vel_y(vy),
			w(width),
			h(height)
		{}

		bool collides(GameObj *other, int ignore = -1);

		virtual ~GameObj(){}

		virtual void update(double elapsed_time) = 0;

		virtual void draw(){}

		virtual void print(){}

		virtual bool handle_message(const Telegram &msg) {
			return false;
		}

		int get_id() const {
			return id;
		}

		int get_type() const {
			return type;
		}

		virtual void get_position(int &px, int &py) {
			px = x;
			py = y;
		}

		virtual void get_velocity(int &vx, int &vy) {
			vx = vel_x;
			vy = vel_y;
		}

		virtual void get_dimensions(int &width, int &height) {
			width = w;
			height = h;
		}

		virtual void bounding_box(int &x1, int &y1, int &x2, int &y2) {
			x1 = x;
			y1 = y;
			x2 = x + w;
			y2 = y + h;
		}

		virtual void resize(int new_width, int new_height) {
			w = new_width;
			h = new_height;
		}

		virtual void set_velocity(int vx, int vy) {
			vel_x = vx;
			vel_y = vy;
		}

		virtual void set_position(int px, int py) {
			x = px;
			y = py;
		}
};

#endif

