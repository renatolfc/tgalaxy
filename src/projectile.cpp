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

#include <cstdio>

#include <tgalaxy.h>
#include <world.h>
#include <gameobj.h>
#include <entitymanager.h>
#include <dispatcher.h>
#include <telegram.h>
#include <projectile.h>
#include <messagetypes.h>
#include <projectile_image.h>

#define x1 x
#define x2 x+w
#define y1 y
#define y2 y-h

const int PROJECTILE_WIDTH = projectile_image.width;
const int PROJECTILE_HEIGHT = projectile_image.height;
const int PROJECTILE_VELOCITY_X = 9;
const int PROJECTILE_VELOCITY_Y = 60;

void Projectile::update(double elapsed_time) {
	double new_x = vel_x * elapsed_time + x;
	double new_y = vel_y * elapsed_time + y;

	x = new_x;
	y = new_y;

	GameObj *temp;

	// No friendly-fire. Ignoring shooter type...
	temp = entities.check_collision(this, shooter);

	if(temp != NULL) {
		// Collided with something
		if(temp->get_type() == PROJECTILE_TYPE) {
			entities.destroy_entity(temp);
		} else {
			dispatcher.dispatch_message(0, get_id(), temp->get_id(), MSG_BEEN_HIT, NULL);
		}
		dispatcher.broadcast(0, SENDER_ID_IRRELEVANT, RECEIVER_TYPE_IRRELEVANT,
				MSG_PROJECTILE_COLLISION, NULL);
		entities.destroy_entity(this);
		return;
	}

	// Keep the simulation going
	int width, height;
	world->dimensions(width, height);
	if(x < 0 || x + w > width ||
			y > height || y - h < 0) {
		// Out of screen, destroy it
		entities.destroy_entity(this);
	}
}

void Projectile::draw() {
	if(vel_y < 0) {
		glPixelZoom(1.0, 1.0);
	}
	else {
		glPixelZoom(1.0, -1.0);
	}

	glRasterPos2d(x1, y1);

	glDrawPixels(projectile_image.width, projectile_image.height,
			projectile_image.bytes_per_pixel == 3 ? GL_RGB : GL_RGBA,
			GL_UNSIGNED_BYTE, projectile_image.pixel_data);

	glPixelZoom(1.0, 1.0);
}

Projectile::~Projectile() {
	dispatcher.dispatch_message(0, get_id(), shooter_id, MSG_PROJECTILE_DESTROYED, NULL);
}

void Projectile::print() {
	using namespace std;
	cout << "Projectile with global id " << id << endl;
	cout << "\tCoordinates: " << x << " " << y << endl;
	cout << "\tVelocities: " << vel_x << " " << vel_y << endl;
	cout << "\tDimensions: " << w << " " << h << endl;
}

#undef x1
#undef x2
#undef y1
#undef y2

