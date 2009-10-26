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

#ifndef TGALAXY_H
#define TGALAXY_H

#include <config.h>
#include <sys/time.h>

#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif // __APPLE__

#ifdef WIN32
	// FIXME: Should remove it
	#define random rand
#endif

#define _C_  ,    /// Debug , to simulate vararg macros

#define PrintFunction() \
	do { fprintf(stdout, "%s:%d: ", __FILE__, __LINE__); } while (0)

#ifdef DEBUG

#include <cstdio>
#include <cstdlib>

#define Assert(cond)  do { if (!(cond)) { \
	fprintf(stderr, "Assertion failed at %s:%d: %s\n", __FILE__, __LINE__, #cond); \
	abort(); }} while (0)

	/**
	**  Print debug information with function name.
	*/
#define DebugPrint(args) \
	do { PrintFunction(); fprintf(stdout, args); } while (0)

#else //DEBUG

#define Assert(cond)        /* disabled */
#define DebugPrint(args)    /* disabled */

#endif

enum heading            {N=0, NW,  W, SW,  S, SE,  E, NE};
const int heading2x[] = {  0, -1, -1, -1,  0, +1, +1, +1};
const int heading2y[] = { +1, +1,  0, -1, -1, -1,  0, +1};

enum {
	OUTCOME_NOT_DEFINED,
	OUTCOME_SUCCESS,
	OUTCOME_FAILURE
};

const int FPS = 60;
const int WINDOW_WIDTH = 550;
const int WINDOW_HEIGHT = 700;
const double FRAME_TIME = 1 / FPS;
const int VELOCITY_BAR_HEIGHT = 22;
const int WINDOW_CENTER_X = WINDOW_WIDTH / 2;
const int WINDOW_CENTER_Y = WINDOW_HEIGHT / 2;

const int SCORE_X = WINDOW_WIDTH - 80;
const int SCORE_Y = WINDOW_HEIGHT - 16;
const int ALIEN_DESTRUCTION_POINTS = 100;

const int WORLD_WIDTH = WINDOW_WIDTH;
const int WORLD_HEIGHT = WINDOW_HEIGHT;

void inline copy_times(struct timeval *dest, struct timeval *src) {
	dest->tv_sec = src->tv_sec;
	dest->tv_usec = src->tv_usec;
}

double inline time_difference(struct timeval *start, struct timeval *end) {
	return (double)((end->tv_sec + end->tv_usec*1e-6) - (start->tv_sec + start->tv_usec*1e-6));
}

double inline double_timeofday() {
	struct timeval current;
	gettimeofday(&current, NULL);

	return (double) current.tv_sec + current.tv_usec*1e-6;
}

#endif

