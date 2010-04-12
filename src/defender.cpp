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

#include <iostream>

#include <tgalaxy.h>
#include <gameobj.h>
#include <defender.h>
#include <projectile.h>
#include <messagetypes.h>
#include <defender_image.h>

const int DEFENDER_WIDTH = defender_image.width;
const int DEFENDER_HEIGHT = defender_image.height;
const int DEFENDER_MAX_SPEED = 120;
const int DEFENDER_MAXIMUM_SHOTS = 4;
const int DEFENDER_DEFAULT_ENERGY = 3;

#define x1 x
#define x2 x+w
#define y1 y
#define y2 y-h

void Defender::update(double elapsed_time) {

    if(energy <= 0) { // Destroyed
        dispatcher.broadcast(0, SENDER_ID_IRRELEVANT, RECEIVER_TYPE_IRRELEVANT,
                MSG_DEFENDER_DESTROYED);
    }

    int width, height;
    double new_x, new_y;

    world->dimensions(width, height);

    if(elapsed_time != 0) {
        new_x = vel_x * elapsed_time + x;
        new_y = vel_y * elapsed_time + y;
    }
    else {
        new_x = x;
        new_y = y;
    }

    x = new_x;
    y = new_y;

    if(new_x < 0) {
        x = 0;
    }

    if(new_x + w > width) {
        x = width - w;
    }

    if(new_y > height) {
        y = height;
    }

    if(new_y - h < 0) {
        y = h;
    }
}

void Defender::print() {
    using namespace std;
    cout << "Defender (player) with global id " << id << endl;
    cout << "\tCoordinates: " << x << ' ' << y << endl;
    cout << "\tVelocities: " << vel_x << ' ' << vel_y << endl;
    cout << "\tDimensions: " << w << ' ' << h << endl;
}

void Defender::draw() {
    glPixelZoom(1.0, -1.0);
    glRasterPos2d(x1, y1);
    glDrawPixels(defender_image.width, defender_image.height,
            defender_image.bytes_per_pixel == 3 ? GL_RGB : GL_RGBA,
            GL_UNSIGNED_BYTE, defender_image.pixel_data);
}

void Defender::set_speed(int vx) {
    vel_x = vx;
}

void Defender::shoot() {
    if(current_shots <= maximum_shots) {
       current_shots += 1;
       Projectile *p = new Projectile(x + (w >> 1), y, N, DEFENDER_TYPE, get_id(), world);
       entities.register_entity(p);
    }
}

bool Defender::handle_message(const Telegram &msg) {
    switch(msg.msg) {
        case MSG_PROJECTILE_DESTROYED:
            {
                current_shots -= 1;
                return true;
            }
        case MSG_BEEN_HIT:
            {
                energy -= 1;
                DebugPrint("Defender has been hit. Current energy: %d\n" _C_ energy);
                return true;
            }
    }
    return false;
}

#undef x1
#undef x2
#undef y1
#undef y2

