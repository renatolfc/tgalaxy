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

#include <cstdlib>
#include <iostream>

#include <star.h>
#include <tgalaxy.h>
#include <gameobj.h>

const int STAR_WIDTH = 2;
const int STAR_HEIGHT = 2;

void Star::draw() {
	glDisable(GL_BLEND);

	glColor3f(r, g, b);

	glBegin(GL_QUADS);
	glVertex3f(x, y, -0.5);
	glVertex3f(x + w, y, -0.5);
	glVertex3f(x + w, y - h, -0.5);
	glVertex3f(x, y - h, -0.5);
	glEnd();

	glEnable(GL_BLEND);
}

void Star::print() {
	using namespace std;
	cout << "Star with global id " << my_id << endl;
	cout << "\tCoordinates: " << x << " " << y << endl;
	cout << "\tVelocities: " << vel_x << " " << vel_y << endl;
	cout << "\tDimensions: " << w << " " << h << endl;
}


