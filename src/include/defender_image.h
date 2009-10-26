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

/* GIMP RGBA C-Source image dump (defender.c) */

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[48 * 48 * 4 + 1];
} defender_image = {
  48, 48, 4,
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\25\27\27\1\0\0\0\0\0\0\0\0\20\35\40\177\20\35\40\177\0\0"
  "\0\0\0\0\0\0\25\27\27\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\32\20\15\0\0\0\0\0`\242n\2"
  "\16\4\12\202\16<G\377\16<G\377\16\4\11\202c\244o\2\0\0\0\0\32\20\15\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\2\24\37\0\0\0\0\0&\3\0/\14\36%\377\31l{\377\31m|\377\15\40&"
  "\377$\2\0/\0\0\0\0\11\26!\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\20\22\27\0\0\0\0\0\0\0\0\0\20\26\27\270"
  "\12DP\377,\213\227\3745\226\242\374\13HU\377\16\25\27\270\0\0\0\0\0\0\0\0"
  "\20\22\27\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0!\26\15\0\0\0\0\0\40\0\0\22\14\25\36\360\27`m\3773\223\236\376"
  "2\220\234\376\17Uc\377\15\25\36\360&\0\0\22\0\0\0\0!\26\15\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\22\24\26\4\0"
  "\0\0\0\17\13\16\235\12""1?\377\32iv\377\"}\210\377\37s~\377\24]i\377\12""3"
  "@\377\17\12\16\235\0\0\0\0\22\24\26\4\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\7-9\1\0\0\0\0\14\33\37\325\17S_\377"
  "\36p|\376\31my\376\36y\204\376\37v\202\376\23Xe\377\15\33\40\325\0\0\0\0"
  "\7.9\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\30\21\16d\5\30#\377\30iv\377)\204\217\3772\210\225\377H\241"
  "\254\377>\236\251\377\34o}\377\4\27!\377\30\21\16d\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\32\20\15\0\32\20\16\0\0\0\0\0"
  "\26\17\15}\10,5\377\33kx\376\"u\201\3772\221\234\376K\253\266\3769\230\244"
  "\377\40y\207\376\13""09\377\25\15\13}\0\0\0\0\26\25\25\0\32\21\15\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0:E\0\0\0\0\0\0\0\0\0\30\12\6\217\12""4"
  "<\377\37s\200\376\34n{\376.\213\227\376D\250\263\376-\215\230\376+\215\231"
  "\376\20@H\377\27\10\5\217\0\0\0\0\0\0\0\0\0""7D\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\30\16\17\0\0\0\0\0\33\4\0\15\15&*\257\22\31\32\363\14""1:\377%\200"
  "\215\377\36r~\3773\221\235\377V\264\277\3777\223\236\377+\220\235\377\17"
  """4<\377\20\26\27\363\14#'\257\36\12\7\15\0\0\0\0\30\17\20\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\31\20\16\0\0\0\0\0\35\16\12*\6.6\377\13\40%\377\13/7\376\32"
  "mz\377\31gs\3775\221\234\376^\272\305\3766\226\241\377%\200\215\377\22:C"
  "\376\11\30\35\377\7-7\377\40\27\23*\0\0\0\0\32\17\14\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\34\12\5\0\0\0\0\0#\22\14(\14""9C\377\12\37&\377\14""4=\377\24^j\376"
  "%~\212\377f\304\317\376\246\353\363\376N\254\267\377%|\212\376\21>H\377\11"
  "\37(\377\13""8B\377\"\17\10(\0\0\0\0\33\12\6\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\32"
  "\5\2\0\0\0\0\0*\33\25'\35RY\377\0\25#\377\10;J\377\31ht\377(\202\216\377"
  "e\304\317\377\255\355\364\377O\254\266\377*\211\224\377\11=K\377\0\30%\377"
  "\32PV\377)\30\20'\0\0\0\0\34\11\2\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\23\23\23\0\0\0\0\0\0\0"
  "\0\0\21\0\0\31/jq\3777\216\232\377\10EQ\376\35q}\376.\220\233\377\\\267\302"
  "\376\240\347\360\376e\304\316\377)\204\220\376\10JW\3764\213\227\377)dk\377"
  "\14\0\0\31\0\0\0\0\0\0\0\0\22\22\22\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\22\22\22\0\0\0\0\0\0\0\0\0\0\0\0\32"
  "\3\0\0D\37Z`\377G\260\273\377G\232\246\377\33am\376%\202\216\377U\255\270"
  "\376\201\325\337\376@\235\250\377\27an\376D\226\241\377N\272\305\377#Za\377"
  "\0\0\0D\0\0\0\32\0\0\0\0\0\0\0\0\20\20\20\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\26\26\26W$#\"\357\"\35"
  "\34\363#^e\376=\244\260\377[\276\311\3764\211\225\377\32r~\377K\246\261\377"
  "T\257\272\377\26kw\377-\202\216\377Y\275\311\376C\251\265\377%q{\376./1\363"
  "+))\357\27\27\27W\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\32\32\32\220:99\377$!$\376*u\177"
  "\376\36cr\376\11\37&\376\14MZ\376\24_k\3777\225\240\376;\231\245\376+\206"
  "\221\377%\177\214\376\25+-\376'ag\376\36r\201\376+-/\376=;;\377\33\33\33"
  "\220\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\27\24\22\0\26"
  "\25\23\2\17\17\16\1\0\0\0\0\0\0\0\26\34\34\34\244654\377\31\31\31\375)do"
  "\377&;C\376*\30\26\377\17\35\40\376\3;H\3775\220\234\376A\242\256\377*\211"
  "\226\377\34""8=\377\33\7\3\376\26,2\377\35Ua\377\27\25\26\375544\377\34\34"
  "\34\244\0\0\0\26\0\0\0\0\17\16\16\1\26\24\23\2\27\25\23\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\26\26\26\0\16\16\35\0\32\27\21\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\12\12\12f\35\35\35\345(((\377'&&\377\22"
  "\21\21\376\11""1:\3775@F\37760.\377\14\16\20\377\0%0\377;\222\235\377U\263"
  "\275\376$\202\217\376\30\33\34\377\21\6\5\377\23\30\32\376\25""9?\377\17"
  "\17\17\376&&%\377(((\377\35\35\35\345\12\12\12f\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\32\22\17\0\16\16\35\0\26\26\26\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\5"
  "\4\4\1\0\0\0\0\0\0\0\0!\0\0\20\24\0\0>\31\27\26\315%&&\377111\377888\375"
  "c_a\3769AC\377\16O]\376\27!%\377'\40\37\376\33\40#\376\2:F\377F\240\254\376"
  "Z\270\303\376*\211\226\377\35""59\372YYW\332\40'(\377\17T`\376LTY\377ief"
  "\376777\375///\377%&&\377\31\26\26\315\23\0\0>&\0\0\20\0\0\0\0\0\0\0\0\27"
  "\22\22\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\15\15\15\0\0\0\0\0\3\0\0\3\0\0\0\0\0\0\0\0\0\0\0!\32\14"
  "\11a\14\21\27\337\13\",\377/8=\377[YY\377;;;\376,,,\377ZYY\376322\376\24"
  "U`\376\13+5\377+\27\25\376+,-\376\34u\202\377I\263\277\376O\272\307\3763"
  "\226\243\377\34DI\3706\\b\313\31""2;\377\14fw\376MZ\\\376kih\376222\3779"
  "99\376[YY\377499\377\11(1\377\12\16\25\337\34\13\5`3\7\0\31\0\0\0\0\0\0\0"
  "\1\22\24\24\2\34\33\33\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\23\23\21"
  "\0\36\0\0\0GHI\0\0\0\0\0\0\0\0\0\0\0\0\23\0\0\0\177\3\12\21\356\16\32!\377"
  "\21BO\377\22dr\3773OV\377_YX\376BCC\377(((\376DDC\3770+*\377\24OW\377\37"
  "s\203\377\10\25\33\377\26""48\377.v\177\377\"EI\377\36CF\376,s|\376\25""3"
  "8\377\4\26\35\377\35q\177\376\37hs\377GIJ\377]Z[\377111\376?@@\377_ZY\376"
  "3OV\377\22cq\377\16MY\377\16'-\377\10\23\27\352\10\0\0[\0\0\0\0\0\0\0\0\0"
  "\0\0\0\26\26\26\0\30\22\20\0\0\0\0\0\0\0\0\0\23\23\21\0\0\0\0\0\0\0\0\1\0"
  "\0\0\0\0\0\0\0\0\0\0-\2\4\7\335\5\34$\377\1-9\377\4(3\373\33bl\376\25gu\377"
  "5NU\376OIH\377WXX\376EDE\376999\377;43\376\14!)\3761\226\243\377>\244\261"
  "\376!ny\376\25\24\24\377\25\4\2\376$\24\22\377\25\25\26\377%s~\376P\255\271"
  "\3769\235\251\377&JP\376XQP\376EFE\377DCD\376WWX\376OIH\3775NU\376\25er\377"
  "\33ly\376\4?N\373\0\"-\377\1\15\20\377\0\0\0\314\3\3\4A1+*\21\0\0\0\0\12"
  """1;\0\0\0\0\0\0\0\0\0\20\20\15\1-()\0\0\0\0\0\0\0\0\0\0\0\0Z\27\24\23\353"
  "(:?\377\2CS\375\12GT\377\16KW\377\33jw\376\33q~\3766PU\376KFE\377ccd\376"
  "kjk\376/./\377CBB\376\34\21\17\3764t|\377H\275\312\376\32@G\377\17\7\6\377"
  "\33\35\35\376_aa\376\32\27\26\377(q|\376n\332\347\376?x\177\377E>=\376\\"
  "ZZ\376...\377iii\376cdd\376KED\3774QX\376\32q~\376\34ly\376\23Vb\377\24X"
  "e\376\0""8C\377&25\377\21\16\15\377\13\17\17z\0\0\0\0\0\0\0\0&+,\2\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\10\24\26\242\"13\377SJI\377<W\\\376\15`n\376\36"
  "ly\377\27an\376\31jv\377\33r\177\3773NT\377KED\377]^^\377{z{\377'''\377>"
  "??\377*$#\377\"/0\3770\214\231\377\21""8E\376\30\24\24\376$%%\377\"##\377"
  ";88\376/t\177\3778\247\265\3770X^\377SFE\377@AA\377%%%\377{z{\377]^^\377"
  "JFE\377=HK\377\35r~\377\31iu\377\26`l\376#y\205\377\13Wf\376;LQ\376732\377"
  "\0\0\0\326\0\0\0\202JHH.\0\0\0\0\0\0\0\0\350\331\344\6\0\0\0\0\0\1\1\242"
  "7`e\377j\177\202\372]SR\377>SZ\377\12Ud\376\30bn\376\23^l\376\33my\377\32"
  "q~\3764OU\376LGF\377JIJ\376VUV\376777\377+++\376478\376\33\21\17\377\33`"
  "k\376\23AO\376:54\377jkk\371\215\216\216\312wss\377't\200\376\36r~\376<<"
  "=\377DDD\376)))\376777\377VUV\376JIJ\376IHH\377JCA\376\37pz\376\32o{\377"
  "\24^k\376\27_l\376\4M[\376?QU\377:33\375\30""05\377\24$&\377\14\13\13\315"
  "\0\6\12\16\0\0\0\0EAD\374\16\6\5\373SOQ\377vmo\377f__\376SNM\376>W\\\376"
  "\14Xc\377\23T`\376\31\\g\376\32jw\377\33p~\3763NU\376WRQ\377CCD\376DDD\376"
  "CCC\377\37\40\40\3760.-\3767:>\377\0""1B\376\13-9\377EAA\377zzz\362\314\312"
  "\314\216\212\205\207\377\36q}\376&t~\376A43\377+--\376\40\40\40\376CCC\377"
  "DDD\376CCC\376USS\377FDC\376\37pz\376\27fr\377\24\\h\376\25T_\376\22\\g\377"
  "8X]\376=77\376632\376=87\377)''\377\14\5\4\377\11\6\5j\21\30\30\377f\217"
  "\224\377\\ij\377V|\200\376Vij\377ecc\377CY]\377\5EQ\377\23JV\377\15""5=\377"
  "\20Wf\377\33p~\3775PW\377OII\377DDD\376DDD\377999\377\"!!\376\37\"!\3770"
  "9<\376\33EO\377\37;?\377=99\376opp\377\266\266\267\377\202|}\376.iq\377."
  "\202\213\377865\376!!!\377##\"\376999\377DDD\377DDD\376MKK\377HFE\377\37"
  "pz\377\21S_\377\14EQ\377\24GO\377\7""9C\3777T[\377411\377\40.1\377&CI\376"
  "(23\377,KQ\377\11\16\17\377\24#%\376S\255\266\377Oil\376Q\237\247\376Rz~"
  "\377`__\376D_f\376\15aq\377\40v\201\376\24Ze\376\26^j\377\27ky\3765PW\376"
  "KFE\377RSS\377\\Z\\\374998\377*'&\377\7!'\376\15O]\376\35bm\376\26GP\376"
  "200\377dee\376\216\215\216\375URR\377#]e\376#z\207\376\33Xb\376\23\31\34"
  "\376)&%\377999\377\\Z\\\374SSS\377IGG\377HFF\376\33jv\376\26cp\377\30es\376"
  "\37o|\376\14Yf\377>Y^\376544\376\30;A\377\31]i\376\32/3\376\33ep\377\5\23"
  "\25\373\24$&\374b\272\304\377F^a\377e\257\270\377\\\205\211\377ccc\377Pg"
  "n\377\0?K\377\20Vc\377\7BO\377\20Wc\377)\220\235\3779W]\377WQO\377dde\377"
  "khk\377\35\34\35\335\33\27\26\304\7&/\376\34jv\377\34q~\376\21Q\\\376()("
  "\377PPP\376TTT\376...\377\30`k\3761\207\225\3763\203\220\377\0\36'\376\34"
  "\27\26\304\35\35\35\335khk\377ede\377TRR\377NJJ\377/\214\230\377\20]k\377"
  "\6@L\377\20Uc\377\0BP\377AW[\377<==\377\33CH\377&r|\377\30""15\377'{\205"
  "\377\10\27\30\374\13\20\20\377Dab\355(22\361A]^\3606@B\360788\360188\360"
  "\5\25\27\360\16\40'\360\11\36%\360\30""6;\3600X\\\360&13\360:76\360FEG\357"
  "A@A\377\25\23\23h\0\0\0\0\7#*\377\35eq\377\27er\376\24Q\\\377@??\376PPP\377"
  "LMM\377C@?\376\32^i\377/\205\222\3769\204\217\377\3\34#\377\0\0\0\0\25\24"
  "\24hA@A\377GEG\357877\360-++\3602W[\360\26""05\360\10\23\27\360\16\")\360"
  "\7\40'\360+46\360'''\360\31+,\360'EH\360\32$%\361+LP\355\7\14\15\377\0\0"
  "\0""7\0\0\0%\0\0\0(\0\0\0'\0\0\0'\0\0\0'\0\0\0'0\25\15'$\0\0''\4\0'\37\0"
  "\0'\4\0\0'\0\0\0'\0\0\0'\0\0\0'\0\0\0-\22\17\6\17\34\4\0+\7+4\377!w\204\377"
  "$\201\216\377\31[e\376>:9\377abb\375\232\227\226\363DOS\377#z\205\376H\250"
  "\264\377-|\211\377\5&.\377\32\1\0+\23\21\10\17\0\0\0-\0\0\0'\0\0\0'\0\0\0"
  "'\0\0\0'#\0\0')\32\21'$\0\0'0\2\0'\0\0\0'\0\0\0'\26\0\0'\12\0\0'\21\0\0("
  "\15\0\0%\2\0\0""7\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\36\7\0\40\16\21\25\362\31\\h\377?\254\271\375)~\211\3773;=\377\\"
  "ZY\365\253\232\232\245Bku\377,\227\243\3762\217\234\375\14HT\377\22\26\30"
  "\362\36\7\0\40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\26\26\26\0\26\24\23\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\34\13\10O\21\20\22\365\22Xd\377\37u\201\377/?B\376^[Z\377\232"
  "\223\225\377N\\b\376\23ep\377\5@N\377\23\25\26\365\32\11\6O\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\26\24\23\0\26\26\26\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\22\21\21\2\0\0\0\0\24\21\22f\31\2\0\206\26\4\0\212\36\0"
  "\0\32\0\0\0\0\25\16\14\202\36\"%\3775>@\376FBA\377XZZ\376\205\205\207\375"
  "_WX\3773<>\376\37%'\377\24\15\13\202\0\0\0\0\37\0\0\32\26\4\0\212\31\2\0"
  "\206\24\21\22f\0\0\0\0\22\21\21\2\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\31\17\15"
  "\0\0\0\0\0\0\0\0\0\23\17\17h\26!$\377\36iu\377\31^i\377\27-1\324\0\0\0\0"
  "\21\15\14\220($$\377HDC\377LMM\377UUU\376utu\376fdg\377FBA\377'##\377\21"
  "\16\16\220\0\0\0\0\30*.\324\31^i\377\36iu\377\26!$\377\24\17\16h\0\0\0\0"
  "\0\0\0\0\24\26\30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\22\30\33\0\0\0\0\0\16*1\3+\0\0\17\26\5\2\212\35"
  "\36\37\377\"aj\377&\211\225\377\31]g\377\23\22\23\332\20!&\377\31\31\31\375"
  "-,,\377CCC\377^_^\377\211\207\211\377fef\377+**\377\30\27\26\375\25\33\34"
  "\377\17\31\34\332\21fs\377'\210\223\377\"ak\377\36\36\36\377\26\6\4\212\35"
  "\15\21\17\15,2\3\0\0\0\0\26\27\26\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0I\0\0\1\15\34\40\336\5"
  "&.\363\32\36\37\377-&$\377FZ_\376U[_\376(DK\377\25n|\376!)*\377810\376??"
  "?\377OOO\376^]^\376DCC\377>87\376!@E\377\21Wb\376&,.\377Lfm\376EY]\376,&"
  "$\377\33\36\37\377\7$+\363\24\25\26\336u\0\0\1\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\25\23\23\2"
  "\0\0\0\0\21\0\0""6\32CJ\377\31s\204\377\33'*\375;20\376c]\\\376mab\377Bt"
  "|\377$\217\235\376\25(,\3763+*\376PPP\377???\376;;;\376KJJ\377E??\376\27"
  "IS\376\25s\202\3761DK\377nbb\377f_^\376;43\376\13""8B\375\23_m\377\20+0\377"
  "\23\0\0""6\0\0\0\0\25\24\24\2\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\22\22\22\0\0\0\0\0\0\0\0\0\32\24\23\3361X^\377\"\210"
  "\230\376\37-0\376?87\377a`_\376hab\377Cy\202\377&\213\230\376\13>H\377.)"
  "(\377CCB\376\37\37\37\377\40\40\40\377III\376:43\377\34""9<\377\27u\202\376"
  "2QY\377gaa\377ljk\376D>>\377\14?H\376\27m{\376\27""05\377\27\23\22\336\0"
  "\0\0\0\0\0\0\0\22\22\22\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\4\2\2f6/.\377?kp\377\36\211\227\377\"13\377G?>\376"
  "`__\377hbb\376F\201\211\377&\223\241\377\11""4>\377*$#\376877\376!!!\376"
  "***\376EEE\3760'&\376#-.\377\27|\212\3772S\\\377c]]\376rqq\377OJH\376\16"
  "AJ\377\24n|\377\35""9>\3772-,\377\6\6\5f\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\31\35\35\35\337\\"
  "WW\377Cag\377\24]i\377\"*,\377PLJ\373dbc\377~w{\377Rx}\377\36fm\377\30\34"
  "\35\377$\36\35\375555\377###\376---\3769::\377'!\40\375\32\37\40\377\27U"
  "`\3777QX\377wps\377\217\214\216\377a[Z\373\37,-\377\24Q[\377\"37\377WTT\377"
  "\37\36\36\337\0\0\0\31\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\34""222\341zwz\377A>@\344\0\0\0O\25\17\16\270"
  "?@@\377pnp\327}}~\3668/-\333\10\0\0M\23\14\13\202466\377333\377&&&\377??"
  "?\377QQQ\377022\377\21\13\13\202\16\0\0M2,)\333\201\202\202\366\213\213\214"
  "\327DEF\377\22\14\13\270\25\0\0O*(&\344usu\377333\341\0\0\0\34\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\1\35\36"
  "\36\36\340;:;\377%$&(\0\0\0\0\0\0\0\10\"!!\303+++\351222\332\20\33\35\"\0"
  "\0\0\0\0\0\0\0$##\323555\377)))\377III\377ggg\377\36\35\35\323\0\0\0\0\0"
  "\0\0\0\34$&\"111\332%$%\351\40\37\37\303\0\2\5\10\0\0\0\0\30\32\34(:::\377"
  "\36\36\36\340\1\1\1\35\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\322\323\322\0\0\0\0\3\0\0\0\1\0\0\0\0nkn\1\0\0\0\0"
  "\0\0\0\0\0\0\0\12\0\0\0\2\0\0\0\0BBB\1\0\0\0\0\15\15\15\"\17\17\17\266//"
  "/\360222\360\27\27\27\266\5\5\5\"\0\0\0\0FFF\1\0\0\0\0\0\0\0\2\0\0\0\12\0"
  "\0\0\0\0\0\0\0WVW\1\0\0\0\0\0\0\0\1\0\0\0\3\323\324\323\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\24\24\24\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\40\40\40\0""222\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\37\37"
  "\37\0\40\40\40\1\0\0\0\0\0\0\0\0&&&\347%%%\347\0\0\0\0\0\0\0\0&&&\1\37\37"
  "\37\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0""222\0\40\40\40\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\24\24\24\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\26\26\26\0\0\0\0\0\26\26\26\1\11\11\11\1\25\25\25"
  "E\26\26\26E\33\33\33\1\20\20\20\1\0\0\0\0\26\26\26\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
};

