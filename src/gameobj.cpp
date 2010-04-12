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

#include <tgalaxy.h>
#include <gameobj.h>

bool GameObj::collides(GameObj *other, int ignore) {
    double x1r1, y1r1, x2r1, y2r1, x1r2, y1r2, x2r2, y2r2;

    if(this == other) {
        // Both are the same
        return false;
    }

    if(other->my_type == ignore) {
        return false;
    }

    x1r1 = this->x;
    y2r1 = this->y;
    x2r1 = this->x+this->w;
    y1r1 = this->y-this->h;

    x1r2 = other->x;
    y2r2 = other->y;
    x2r2 = other->x+other->w;
    y1r2 = other->y-other->h;

    if(y2r1 < y1r2) {
        return false;
    }

    if(y1r1 > y2r2) {
        return false;
    }

    if(x2r1 < x1r2) {
        return false;
    }

    if(x1r1 > x2r2) {
        return false;
    }

    return true;
}

