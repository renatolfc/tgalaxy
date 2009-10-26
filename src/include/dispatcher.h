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

#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <map>
#include <set>
#include <string>

#include <telegram.h>

class GameObj;
class GameWorld;
class EntityManager;
class MessageDispatcher;

extern MessageDispatcher dispatcher;

extern void *NO_ADDITIONAL_INFO;
extern const int SENDER_ID_IRRELEVANT;
extern const int RECEIVER_TYPE_IRRELEVANT;
extern const double SEND_MESSAGE_IMMEDIATELY;

class MessageDispatcher {
	private:
		std::set<Telegram> priority_queue;

		EntityManager *entity_manager;

		GameWorld *world;

		void discharge(GameObj *receiver, const Telegram &msg);

	public:

		MessageDispatcher(EntityManager *em) : entity_manager(em), world(NULL) {}

		void dispatch_message(double delay, int sender, int receiver, int msg, void *extra_info);
		void broadcast(double delay, int sender, int receiver_type, int msg, void *extra_info = NULL);
		void dispatch_delayed_messages();

		void subscribe_game(GameWorld *w) {
			// This is not even by far a good design. The best way to
			// do it would be to add some kind of callback system. Since I'm
			// not sure about how I'd do it. I'll leave the current
			// implementation here.
			world = w;
		}
};

#endif

