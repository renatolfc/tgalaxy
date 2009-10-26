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

#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#ifdef DEBUG
#include <string>
#endif

#include <state.h>
#include <typeinfo>
#include <telegram.h>

template <class object_type>
class StateMachine {
	private:

		object_type *owner;

		State<object_type> *previous_state;
		State<object_type> *current_state;
		State<object_type> *global_state;

	public:

		StateMachine(object_type *own) :
			owner(own),
			previous_state(NULL),
			current_state(NULL),
			global_state(NULL)
		{}

		virtual ~StateMachine(){}

		void set_previous_state(State<object_type> *s) {
			previous_state = s;
		}

		void set_current_state(State<object_type> *s) {
			current_state = s;
		}

		void set_global_state(State<object_type> *s) {
			global_state = s;
		}

		void update() const {
			if(global_state) {
				global_state->execute(owner);
			}
			if(current_state) {
				current_state->execute(owner);
			}
		}

		virtual void draw() const {
			if(current_state) {
				current_state->draw(owner);
			}
		}

		bool handle_message(const Telegram &message) const {
			if(current_state && current_state->on_message(owner, message)) {
				return true;
			}

			if(global_state && global_state->on_message(owner, message)) {
				return true;
			}

			return false;
		}

		void change_state(State<object_type> *new_state) {
			Assert(new_state && "<StateMachine::change_state>: trying to assign null state to current");

			previous_state = current_state;
			current_state->exit(owner);
			current_state = new_state;
			current_state->enter(owner);
		}

		void revert_state() {
			change_state(previous_state);
		}

		bool is_in_state(const State<object_type> &s) const {
			if(typeid(*current_state) == typeid(s)) {
				return true;
			}
			return false;
		}

		State<object_type> *get_current_state() const {
			return current_state;
		}

		State<object_type> *get_global_state() const {
			return global_state;
		}

		State<object_type> *get_previous_state() const {
			return previous_state;
		}

#ifdef DEBUG
		std::string get_name_of_current() const {
			std::string s(typeid(*current_state).name());

			return s;
		}
#endif // DEBUG
};

#endif // STATEMACHINE_H

