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

#include <set>
#include <map>

#include <tgalaxy.h>
#include <entitymanager.h>
#include <dispatcher.h>
#include <telegram.h>
#include <gameobj.h>
#include <world.h>

using std::set;
using std::map;

MessageDispatcher dispatcher(&entities);

void *NO_ADDITIONAL_INFO = 0;
const int SENDER_ID_IRRELEVANT = -1;
const int RECEIVER_TYPE_IRRELEVANT = -1;
const double SEND_MESSAGE_IMMEDIATELY = 0.0;

void MessageDispatcher::discharge(GameObj *receiver, const Telegram &msg)
{
    if(receiver == NULL) {
        DebugPrint("Receiver doesn't exist anymore\n");
    }
    if(!receiver->handle_message(msg)) {
        DebugPrint("Message %d not handled.\n" _C_ msg.msg);
    }
}

void MessageDispatcher::dispatch_message(double delay,
        int sender, int receiver, int msg, void *extra_info = NULL)
{
    GameObj *preceiver = entity_manager->get_entity_from_id(receiver);

    if(entity_manager->reset) {
        return;
    }

    if(preceiver == NULL) {
        DebugPrint("No receiver with ID %d\n" _C_ receiver);
        return;
    }

    Telegram telegram(0, sender, receiver, msg, extra_info);

    if(delay <= 0.0) {
        DebugPrint("Telegram dispatched by %d for %d with ID %d\n"
                _C_ sender _C_ receiver _C_ msg);
        discharge(preceiver, telegram);
    }
    else {
        // Not implemented
        DebugPrint("Delayed telegrams not implemented. Sending anyway.\n");
        DebugPrint("Telegram dispatched by %d for %d with ID %d\n"
                _C_ sender _C_ receiver _C_ msg);
        discharge(preceiver, telegram);
    }
}

void MessageDispatcher::dispatch_delayed_messages() {
}

void MessageDispatcher::broadcast(double delay, int sender, int receiver_type, int msg, void *extra_info) {
    map<int, GameObj *>::const_iterator it;
    GameObj *temp;

    if(receiver_type != RECEIVER_TYPE_IRRELEVANT) {
        for(it = entity_manager->entities.begin(); it != entity_manager->entities.end(); ++it) {
            temp = it->second;
            if(temp->type() != receiver_type) {
                continue;
            }
            dispatch_message(delay, sender, it->first, msg, extra_info);
        }
    }

    if(world != NULL) {
        // Read the note in MessageDispatcher::subscribe_game
        world->handle_message(msg, sender, receiver_type, extra_info);
    }

}

