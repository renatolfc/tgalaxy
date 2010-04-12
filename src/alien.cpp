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
#include <alien.h>
#include <telegram.h>
#include <alienstates.h>

const int ALIEN_ROWS = 4;
const int ALIENS_IN_ROW = 8;
const int ALIEN_WIDTH = alien_image.width;
const int ALIEN_HEIGHT = alien_image.height;
const int ALIEN_MAXIMUM_SHOTS = 3;
const int DEFAULT_ALIEN_ENERGY = 1;
const int DEFAULT_X_SPEED = 30;
const int DEFAULT_Y_SPEED = -6;
const int ALIEN_EXPLOSION_DURATION = 2.0;
const float ALIEN_FIRING_RATE = 1.0 / 10000;
const int ALIEN_OFFSET = 36;
const int ALIEN_SPACING = 10;

#define x1 x
#define x2 x+w
#define y1 y
#define y2 y-h

Alien::Alien(int row, int col, GameWorld *w) : 
    GameObj(ALIEN_TYPE,
            col_to_x(col),
            row_to_y(row),
            DEFAULT_X_SPEED, DEFAULT_Y_SPEED,
            ALIEN_WIDTH,
            ALIEN_HEIGHT)
        {
            Assert(w);
            world = w;
            state_machine = new StateMachine<Alien>(this);
            state_machine->set_current_state(&alien_squad_state);
            etime = 0;
            accumulated_time = 0;
            current_animation_frame = 0;
            direction = RIGHT;
            c = col;
            r = row;
            energy = DEFAULT_ALIEN_ENERGY;
        }


void Alien::update(double elapsed_time) {
    etime = elapsed_time;
    accumulated_time += etime;

    state_machine->update();
}

void Alien::shoot() {
    Projectile *p = new Projectile(x + (w >> 1), y - h - PROJECTILE_HEIGHT, S,
            ALIEN_TYPE, id(), world);
    entities.register_entity(p);
    DebugPrint("Allocated projectile with address %p by entity %d\n" _C_ p
            _C_ id());
}

void Alien::draw() {
    state_machine->draw();
}

void Alien::print() {
    using namespace std;
    cout << "Alien with global id " << my_id << endl;
    cout << "\tCoordinates: " << x << ' ' << y << endl;
    cout << "\tVelocities: " << vel_x << ' ' << vel_y << endl;
    cout << "\tDimensions: " << w << ' ' << h << endl;
}

bool Alien::handle_message(const Telegram &msg) {
    return state_machine->handle_message(msg);
}

#undef x1
#undef x2
#undef y1
#undef y2


