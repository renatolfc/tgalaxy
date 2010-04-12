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

#include <tgalaxy.h>

#include <alien.h>
#include <gameobj.h>
#include <entitymanager.h>

EntityManager entities;

GameObj *EntityManager::get_entity_from_id(int id) const {
    EntityMap::const_iterator ent = entities.find(id);

    if(ent == entities.end()) {
        return NULL;
    }

    return ent->second;
}

bool EntityManager::remove_entity(GameObj *entity) {
    if(updating) {
        remove_buffer.push(entity);
    }
    else {
        EntityMap::const_iterator ent = entities.find(entity->get_id());
        if(ent != entities.end()) {
            entities.erase(ent->first);
            return true;
        }
        return false;
//      DebugPrint("Erasing entity with id: %d\n" _C_ entity->id());
    }
    return false;
}

void EntityManager::destroy_entity(GameObj *entity) {
    if(updating) {
        delete_buffer.push(entity);
    }
    else {
        if(remove_entity(entity)) {
            delete entity;
        }
        else {
            DebugPrint("No entity to deallocate at address %p\n" _C_ entity);
        }
    }
}

void EntityManager::register_entity(GameObj *new_entity) {
//  DebugPrint("Registering entity with address %p\n" _C_ new_entity);
    if(updating) {
        insert_buffer.push(new_entity);
    }
    else {
        entities.insert(std::make_pair(new_entity->get_id(), new_entity));
    }
}

GameObj *EntityManager::check_collision(GameObj *requester, int ignore) {
    GameObj *temp;
    std::map<int, GameObj *>::const_iterator itr;

    for(itr = entities.begin(); itr != entities.end(); ++itr) {
        temp = (*itr).second;

        if(requester->collides(temp, ignore)) {
            if(temp->get_type() == STAR_TYPE) {
                continue;
            }
            if(temp->get_type() == ALIEN_TYPE) {
                Alien *a = dynamic_cast<Alien *>(temp);
                if(a->current_energy() <= 0) {
                    continue;
                }
            }
            return temp;
        }
    }

    return NULL;
}

void EntityManager::update_all(double elapsed_time) {
    GameObj *temp;
    std::map<int, GameObj *>::const_iterator itr;

    if(reset) {
        reset = false;
    }

    updating = true;
    for(itr = entities.begin(); itr != entities.end(); itr++) {

        if(reset) {
            return;
        }

        temp = (*itr).second;
        if(temp != NULL) {
            temp->update(elapsed_time);
        }
    }
    updating = false;

    while(!insert_buffer.empty()) {
        this->register_entity(insert_buffer.front());
        insert_buffer.pop();
    }

    while(!delete_buffer.empty()) {
        this->destroy_entity(delete_buffer.front());
        delete_buffer.pop();
    }

    while(!remove_buffer.empty()) {
        this->remove_entity(remove_buffer.front());
        remove_buffer.pop();
    }
}

void EntityManager::draw_all() {
    GameObj *temp;
    std::map<int, GameObj *>::reverse_iterator rit;

    for(rit = entities.rbegin(); rit != entities.rend(); ++rit) {
        // Iterating backwards because projectiles are registered later
        temp = (*rit).second;
        temp->draw();
    }
}

void EntityManager::print_all() {
    GameObj *temp;
    std::map<int, GameObj *>::const_iterator itr;

    for(itr = entities.begin(); itr != entities.end(); ++itr) {
        temp = (*itr).second;
        temp->print();
    }
}

void EntityManager::destroy_all() {
    GameObj *temp;
    std::map<int, GameObj *>::const_iterator itr;

    reset = true;

    for(itr = entities.begin(); itr != entities.end(); ++itr) {
        temp = (*itr).second;
        delete temp;
    }

    entities.clear();
}

