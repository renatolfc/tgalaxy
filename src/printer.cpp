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

#include <cstring>

#include <tgalaxy.h>
#include <printer.h>
#include <font.h>

void Printer::build_font() {
	float cx, cy;

	DebugPrint("Building font...\n");

	base = glGenLists(256);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	for (int i = 0; i < 256; i++) {
		cx = float(i%16)/16.0f;
		cy = float(i/16)/16.0f;
		glNewList(base + i, GL_COMPILE);

		glBegin(GL_QUADS);
			glTexCoord2f(cx, 1 - cy - 0.0625f);
			glVertex2i(0, 0);

			glTexCoord2f(cx + 0.0625f, 1 - cy - 0.0625f);
			glVertex2i(16, 0);

			glTexCoord2f(cx + 0.0625f, 1 - cy);
			glVertex2i(16, 16);

			glTexCoord2f(cx, 1 - cy);
			glVertex2i(0, 16);
		glEnd();

		glTranslated(10, 0, 0);
		glEndList();
	}
	DebugPrint("Font built\n");
}

void Printer::kill_font() {
	glDeleteLists(base, 256);
}

void Printer::load_texture() {
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	glTexImage2D(GL_TEXTURE_2D, 0, font.bytes_per_pixel, font.width, 
			font.height, 0, font.bytes_per_pixel == 3 ? GL_RGB :
			GL_RGBA, GL_UNSIGNED_BYTE, font.pixel_data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	DebugPrint("Finished loading textures.\n");
}

Printer::Printer() {
	glEnable(GL_TEXTURE_2D);
		load_texture();
		build_font();
	glDisable(GL_TEXTURE_2D);
}

Printer::~Printer() {
	glEnable(GL_TEXTURE_2D);
		kill_font();
	glDisable(GL_TEXTURE_2D);
}

void Printer::print(int x, int y, const char *string, int set) {
	glEnable(GL_TEXTURE_2D);

	if(set > 1) {
		set = 1;
	}
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0.0, (float)WINDOW_WIDTH, 0.0, (float)WINDOW_HEIGHT, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslated(x, y, 0);
	glListBase(base - 32 + (128 * set));
	glCallLists(strlen(string), GL_BYTE, string);

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);

}

