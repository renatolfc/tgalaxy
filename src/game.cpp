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

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

#include <messagetypes.h>
#include <defender.h>
#include <tgalaxy.h>
#include <printer.h>
#include <game.h>

Game::Game(int argc, char **argv) : debug(false), aliens(0), step(0), score(0) {
	// Constructor and application initializer

	srand(time(NULL));

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_STENCIL);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	glutCreateWindow("tgalaxy");

	glClearColor(0, 0, 0, 0);

	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, (float)WINDOW_WIDTH, 0.0, (float)WINDOW_HEIGHT, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glEnable(GL_BLEND);

	glutWarpPointer(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);

	world = new GameWorld(WINDOW_WIDTH, WINDOW_HEIGHT, this);
	printer = new Printer();

}

void Game::mouse_callback(int button, int state, int x, int y) {
	if(state != GLUT_DOWN) {
		// Only one kind of button presses matter to me
		return;
	}
	switch(button) {
		case GLUT_LEFT_BUTTON:
			if(current_outcome == OUTCOME_NOT_DEFINED) {
				world->defender_shoot();
			}
			break;
		case GLUT_MIDDLE_BUTTON:
			if(!debug) {
				debug = true;
				world->pause();
				world->print();
				std::cout << "Current time step: " << step << std::endl;
			}
			else {
				world->toggle_pause();
				update_game();
				world->print();
				std::cout << "Current time step: " << step << std::endl;
				world->toggle_pause();
			}
			break;
		case GLUT_RIGHT_BUTTON:
			debug = false;
			world->toggle_pause();
			break;
	}
}

void Game::keyboard_callback(unsigned char key, int x, int y) {
	switch(key) {
		case 27: // ESC keycode
			exit(0);
			break;
		case 'p':
		case 'P':
			debug = false;
			world->toggle_pause();
			break;
		case 'r':
		case 'R':
			step = 0;
			debug = false;
			world->restart();
			break;
		case 'd':
		case 'D':
			if(!debug) {
				debug = true;
				world->pause();
				world->print();
				std::cout << "Current time step: " << step << std::endl;
			}
			else {
				world->toggle_pause();
				update_game();
				world->print();
				std::cout << "Current time step: " << step << std::endl;
				world->toggle_pause();
			}
			break;
	}
}

void Game::passive_motion_callback(int x, int y) {
	int delta = x - WINDOW_CENTER_X;

	if(dead_zone(x)) {
		world->defender_speed(0);
	}
	else {
		world->defender_speed(2 * delta * DEFENDER_MAX_SPEED / WINDOW_WIDTH);
	}
	if(current_outcome == OUTCOME_NOT_DEFINED) {
		world->mouse_position(x, y);
	}
}

void Game::reshape_callback(int w, int h) {
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, (float)WINDOW_WIDTH, 0.0, (float)WINDOW_HEIGHT, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Game::draw_game() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glColor3f(1.0, 1.0, 1.0);

	glLoadIdentity();

	glColor3f(1.0, 0, 0);

	world->draw();
	draw_velocity_bar();
	draw_score();
	draw_energy(world->defender->current_energy());

	if(current_outcome != OUTCOME_NOT_DEFINED) {
		draw_outcome();
	}

	glPopMatrix();

	glutSwapBuffers();
}

void Game::draw_outcome() {
	if(current_outcome == OUTCOME_NOT_DEFINED) {
		return;
	}
	if(current_outcome == OUTCOME_SUCCESS) {
		glColor3f(1, 1, 1);
		printer->print(WINDOW_WIDTH / 8, WINDOW_HEIGHT / 2 + 16,
				"CONGRATULATIONS! You saved the Earth! :)", 0);
		glColor3f(0, 0, 0.7);
	}
	else {
		glColor3f(1, 1, 1);
		printer->print(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2 + 16,
				"Mankind's been destroyed...", 0);
		printer->print(WINDOW_WIDTH / 4, WINDOW_HEIGHT / 2 - 16,
				"... and that's YOUR fault!", 1);
		glColor3f(0.7, 0, 0);
	}
	glBegin(GL_QUADS);
		glVertex2i(1, 1);
		glVertex2i(world->width, 1);
		glVertex2i(world->width, world->height);
		glVertex2i(1, world->height);
	glEnd();
}

void Game::update_game() {
	if(lock_fps(FRAME_TIME)) {
		world->update_simulation();
		glutPostRedisplay();
		if(!world->is_paused()) {
			step += 1;
		}
	}
}

void Game::draw_velocity_bar() {
	glColor3f(0.5, 0.5, 0);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_BLEND);

	glBegin(GL_QUADS);
	int vx, vy;
	world->defender->get_velocity(vx, vy);
		if(vx < 0) {
			glVertex2i(world->width >> 1, 1);
			glVertex2i(world->width >> 1, VELOCITY_BAR_HEIGHT);

			glColor3f(0.9, 0, 0);

			glVertex2i(world->mouse_x, VELOCITY_BAR_HEIGHT);
			glVertex2i(world->mouse_x, 1);
		}
		else {
			glVertex2i(world->width >> 1, VELOCITY_BAR_HEIGHT);
			glVertex2i(world->width >> 1, 1);

			glColor3f(0.9, 0, 0);

			glVertex2i(world->mouse_x, 1);
			glVertex2i(world->mouse_x, VELOCITY_BAR_HEIGHT);
		}

	glEnd();

	glColor3f(0.5, 0.5, 0);

	glBegin(GL_LINES);
		glVertex2i(0, 1);
		glVertex2i(world->width, 1);
		glVertex2i(0, VELOCITY_BAR_HEIGHT);
		glVertex2i(world->width, VELOCITY_BAR_HEIGHT);
		glVertex2i(world->width >> 1, 1);
		glVertex2i(world->width >> 1, VELOCITY_BAR_HEIGHT);
	glEnd();

	glPopMatrix();
	glEnable(GL_BLEND);
}

void Game::draw_score() {
	char score_text[] = "Score";
	char score_value[6];

	snprintf(score_value, 6, "%05d", (int)score);

	glColor3f(0.9, 0.9, 0.9);
	printer->print(SCORE_X, SCORE_Y, score_text, 0);
	printer->print(SCORE_X, SCORE_Y - 20, score_value, 0);
}

void Game::draw_energy(int energy) {
	char energy_text[] = "Energy";
	int energy_width = strlen(energy_text) * 16;

	int offset_x = 20;
	int offset_y = SCORE_Y - 2;
	float percentage = (float)energy / (float)DEFENDER_DEFAULT_ENERGY;

	printer->print(offset_x, SCORE_Y, energy_text, 0);

	offset_x -= 12;

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glDisable(GL_BLEND);

	// FIXME: The following code assumes the player energy will never be
	// higher than the default!


	if(percentage > 0.67) {
		glColor3f(0.0, 0.7, 0.0);
	}
	else if(percentage > 0.34) {
		glColor3f(0.7, 0.7, 0.0);
	}
	else {
		glColor3f(0.7, 0.0, 0.0);
	}

	glBegin(GL_QUADS);
		glVertex2f(offset_x, offset_y);
		glVertex2f(offset_x + energy_width * percentage, offset_y);
		glVertex2f(offset_x + energy_width * percentage, offset_y - 16);
		glVertex2f(offset_x, offset_y - 16);
	glEnd();

	glColor3f(0.9, 0.9, 0.9);
	glBegin(GL_LINES);
		glVertex2i(offset_x, offset_y);
		glVertex2i(offset_x, offset_y - 16);

		glVertex2i(offset_x, offset_y - 16);
		glVertex2i(offset_x + energy_width, offset_y - 16);

		glVertex2i(offset_x + energy_width, offset_y - 16);
		glVertex2i(offset_x + energy_width, offset_y);

		glVertex2i(offset_x, offset_y);
		glVertex2i(offset_x + energy_width, offset_y);
	glEnd();

	glPopMatrix();
	glEnable(GL_BLEND);

}

