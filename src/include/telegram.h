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

#ifndef TELEGRAM_H
#define TELEGRAM_H

#include <iostream>
#include <cmath>

//these telegrams will be stored in a priority queue. Therefore the >
//operator needs to be overloaded so that the PQ can sort the telegrams
//by time priority. Note how the times must be smaller than
//SmallestDelay apart before two Telegrams are considered unique.

const double smallest_delay = 0.01;

class Telegram
{
	public:
		//the entity that sent this telegram
		int sender;

		//the entity that is to receive this telegram
		int receiver;

		//the message itself. These are all enumerated in the file
		//"MessageTypes.h"
		int msg;

		//messages can be dispatched immediately or delayed for a specified amount
		//of time. If a delay is necessary this field is stamped with the time 
		//the message should be dispatched.
		double dispatch_time;

		//any additional information that may accompany the message
		void *extra_info;


		Telegram() :
			sender(-1),
			receiver(-1),
			msg(-1),
			dispatch_time(-1)
		{}

		Telegram(double time, int s, int r, int m, void* info = NULL):
			sender(s),
			receiver(r),
			msg(m),
			dispatch_time(time),
			extra_info(info)
		{}
};


inline bool operator==(const Telegram& t1, const Telegram& t2)
{
	return (fabs(t1.dispatch_time - t2.dispatch_time) < smallest_delay) &&
	       (t1.sender == t2.sender)        &&
	       (t1.receiver == t2.receiver)    &&
	       (t1.msg == t2.msg);
}

inline bool operator<(const Telegram& t1, const Telegram& t2)
{
	if (t1 == t2) {
		return false;
	}

	else {
		return (t1.dispatch_time < t2.dispatch_time);
	}
}

inline std::ostream& operator<<(std::ostream& os, const Telegram& t)
{
	os << "time: " << t.dispatch_time << "  Sender: " << t.sender
	   << "   Receiver: " << t.receiver << "   Msg: " << t.msg;

	return os;
}

//handy helper function for dereferencing the ExtraInfo field of the Telegram 
//to the required type.
template <class T>
inline T dereference_to_type(void* p)
{
	return *(T*)(p);
}

#endif
