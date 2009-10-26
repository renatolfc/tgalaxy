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

#ifndef ALIEN_IMAGE_H
#define ALIEN_IMAGE_H

static const struct {
  unsigned int 	 width;
  unsigned int 	 height;
  unsigned int 	 bytes_per_pixel; /* 3:RGB, 4:RGBA */ 
  unsigned char	 pixel_data[3][32 * 32 * 3 + 1];
} alien_image = {
  32, 32, 3, {
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0)))111111898\30\30\30\0\0\0\0\0\0""1"
  "11111\40\40\40\40\40\40\40\40\40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0)))111111898\30\30\30\0\0\0\0\0\0""111111\40\40\40\40\40\40\40\40"
  "\40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\20\20\20@A@@A@QRQQRQYZYQRQ\40\40\40"
  "\40\40\40QRQ898111))))))\40\40\40\30\30\30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0))))))IJIhjhy{yhjh"
  "hjhhjhaba898898aba@A@@A@111111)))\40\40\40\40\40\40\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0""111IJIIJIhjh\222\224"
  "\223\241\244\242\201\203\202\201\203\202qsqhjh@A@@A@qsqQRQ@A@@A@@A@111))"
  "))))\40\40\40\40\40\40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\40\40\40@A@abaaba\201\203\202\211\213\212\211\213\212qsqqsqhjhQRQ11"
  "1111YZYQRQQRQIJIIJI898111)))\30\30\30\30\30\30\10\10\10\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\40\40\40@A@abaaba\201\203\202\211\213\212"
  "\211\213\212qsqqsqhjhQRQ111111YZYQRQQRQIJIIJI898111)))\30\30\30\30\30\30"
  "\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0,\4\4v\35\36\177\"$ab"
  "aabaqsqQRQ@A@111111\40\40\40\30\30\30\20\20\20\20\20\20)))\30\30\30""111"
  "@A@@A@IJI@A@\40\40\40\20\20\20\20\20\20\177\"$5\6\6\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0>\10\10l\31\32\265Z\\\210')\210')@A@111898@A@@A@111G\13\13"
  "Q\16\16Q\16\16c\24\24))))))\40\40\40\40\40\40""111)))\40\40\40\241;>\241"
  ";>G\13\13>\10\10\0\0\0\0\0\0\0\0\0\0\0\0""5\6\6""5\6\6c\24\24l\31\32\241"
  ";>\274fg\274fgv\35\36""898IJI111111c\24\24v\35\36\210')\210')v\35\36Q\16"
  "\16\30\30\30""898898111\30\30\30\274fg\23326\23326Z\21\21>\10\10""5\6\6""5"
  "\6\6\0\0\0\0\0\0""5\6\6""5\6\6c\24\24l\31\32\241;>\274fg\274fgv\35\36""8"
  "98IJI111111c\24\24v\35\36\210')\210')v\35\36Q\16\16\30\30\30""898898111\30"
  "\30\30\274fg\23326\23326Z\21\21>\10\10""5\6\6""5\6\6\0\0\0\0\0\0G\13\13G"
  "\13\13l\31\32\177\"$\241;>Z\21\21Z\21\21IJIIJIhjh898898\177\"$\250EG\233"
  "26\23326\221,.Z\21\21)))898898@A@111\40\40\40\177\"$\177\"$Z\21\21G\13\13"
  ">\10\10>\10\10\0\0\0\0\0\0Z\21\21Z\21\21l\31\32\221,.5\6\6@A@@A@QRQQRQy{"
  "y@A@@A@\23326\303rs\241;>\241;>\23326l\31\32\30\30\30""111111@A@898)))\40"
  "\40\40\40\40\40c\24\24Q\16\16""5\6\6""5\6\6\0\0\0\0\0\0c\24\24c\24\24v\35"
  "\36G\13\13\0\0\0IJIIJIabaqsq\211\213\212898898\250EG\353\306\306\257OQ\257"
  "OQ\23326l\31\32\20\20\20))))))@A@898)))\0\0\0\0\0\0G\13\13c\24\24G\13\13"
  "G\13\13\0\0\0\0\0\0c\24\24c\24\24G\13\13\0\0\0\0\0\0\0\0\0\0\0\0)))89811"
  "1111111\23326\311~\177\257OQ\257OQ\177\"$c\24\24\20\20\20\30\30\30\30\30"
  "\30\40\40\40\40\40\40\0\0\0\0\0\0\0\0\0\0\0\0Q\16\16Q\16\16Q\16\16\0\0\0"
  "\0\0\0c\24\24c\24\24G\13\13\0\0\0\0\0\0\0\0\0\0\0\0)))898111111111\23326"
  "\311~\177\257OQ\257OQ\177\"$c\24\24\20\20\20\30\30\30\30\30\30\40\40\40\40"
  "\40\40\0\0\0\0\0\0\0\0\0\0\0\0Q\16\16Q\16\16Q\16\16\0\0\0\0\0\0c\24\24c\24"
  "\24""5\6\6\0\0\0\0\0\0\30\30\30\30\30\30)))898@A@898898v\35\36\221,.\177"
  "\"$\177\"$Q\16\16G\13\13\40\40\40)))))))))\40\40\40\20\20\20\0\0\0\0\0\0"
  "\0\0\0G\13\13c\24\24c\24\24\20\1\1\0\0\0c\24\24c\24\24\20\1\1\0\0\0\0\0\0"
  "))))))IJIhjhIJI@A@@A@111Q\16\16Q\16\16Q\16\16""5\6\6\40\40\40)))@A@@A@IJ"
  "I111\20\20\20\20\20\20\20\20\20\0\0\0\30\14\1\177\"$\177\"$\20\1\1\0\0\0"
  "c\24\24c\24\24\30\14\1\0\0\0\0\0\0))))))hjh\222\224\223YZY898898111qsq))"
  "))))YZY\30\30\30""111QRQQRQqsq898\20\20\20\10\10\10\10\10\10\0\0\0\10\10"
  "\10\177\"$\177\"$\20\1\1\0\0\0c\24\24c\24\24Q\16\16\0\0\0\0\0\0\20\20\20"
  "\20\20\20""898IJI898\40\40\40\40\40\40\40\40\40Q\16\16c\24\24c\24\24c\24"
  "\24\40\40\40)))898898@A@111\0\0\0\20\20\20\20\20\20\0\0\0c\24\24\221,.\221"
  ",.\0\0\0\0\0\0c\24\24c\24\24Q\16\16\0\0\0\0\0\0\20\20\20\20\20\20""898IJ"
  "I898\40\40\40\40\40\40\40\40\40Q\16\16c\24\24c\24\24c\24\24\40\40\40)))8"
  "98898@A@111\0\0\0\20\20\20\20\20\20\0\0\0c\24\24\221,.\221,.\0\0\0\0\0\0"
  """5\6\6""5\6\6c\24\24\20\20\20\30\30\30\10\10\10\10\10\10\30\30\30))))))"
  "111111898v\35\36\257OQ\257OQv\35\36""111)))\40\40\40\40\40\40\40\40\40\0"
  "\0\0\0\0\0\0\0\0\0\0\0v\35\36\241;>\20\1\1\20\1\1\0\0\0\0\0\0\0\0\0\0\0\0"
  "G\13\13v\35\36\20\20\20\30\30\30\30\30\30\20\20\20\40\40\40\20\20\20""89"
  "8898hjh898Q\16\16Q\16\16""898aba111\40\40\40\40\40\40\30\30\30\30\30\30\20"
  "\20\20l\31\32l\31\32\221,.\30\14\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\20"
  "\1\1""5\6\6c\24\24Q\16\16Q\16\16Q\16\16G\13\13\0\0\0""898898QRQ)))\0\0\0"
  "\0\0\0""111IJI898\0\0\0\0\0\0Q\16\16Q\16\16c\24\24c\24\24c\24\24\10\10\10"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\20\1\1""5\6\6c\24\24Q\16\16Q\16"
  "\16Q\16\16G\13\13\0\0\0""898898QRQ)))\0\0\0\0\0\0""111IJI898\0\0\0\0\0\0"
  "Q\16\16Q\16\16c\24\24c\24\24c\24\24\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\20\1\1\30\14\1\30\14\1\20\1\1\0\0\0\0\0\0""89"
  "8898QRQ\0\0\0\0\0\0\0\0\0\0\0\0IJI898\0\0\0\0\0\0\0\0\0\0\0\0\10\10\10\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0""898898QRQ\0\0\0\0\0\0\0\0\0\0\0\0IJI"
  "898\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\40\40"
  "\40\40\40\40QRQ@A@\0\0\0\0\0\0\40\40\40YZY)))\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0)))aba\0\0\0\0\0\0YZY)"
  "))\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0)))aba\0\0\0\0\0\0YZY)))\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0",
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0)))111111898"
  "\30\30\30\0\0\0\0\0\0""111111\40\40\40\40\40\40\40\40\40\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0)))111111898\30\30\30\0\0\0\0\0\0""11111"
  "1\40\40\40\40\40\40\40\40\40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\20\20\20\20\20"
  "\20@A@@A@QRQQRQYZYQRQ\40\40\40\40\40\40QRQ898111111)))\40\40\40\30\30\30"
  "\30\30\30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0)))IJIIJIhjhy{yhjhhjhhjhaba898898aba@A@@A@@A@111)))\40\40\40"
  "\40\40\40\40\40\40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0""111IJIhjhhjh\222\224\223\241\244\242\201\203\202\201\203\202"
  "qsqhjh@A@@A@qsqQRQ@A@@A@@A@111)))))))))\40\40\40\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0""111IJIhjhhjh\222\224\223\241\244\242"
  "\201\203\202\201\203\202qsqhjh@A@@A@qsqQRQ@A@@A@@A@111)))))))))\40\40\40"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\40\40\40@A@aba\201"
  "\203\202\201\203\202\211\213\212\211\213\212qsqqsqhjhQRQ111111YZYQRQQRQQ"
  "RQIJI898111111)))\30\30\30\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0,"
  "\4\4,\4\4v\35\36\177\"$abaqsqqsqQRQ@A@111111\40\40\40\30\30\30\20\20\20\20"
  "\20\20)))\30\30\30""111111@A@IJI@A@@A@\40\40\40\20\20\20\177\"$5\6\6""5\6"
  "\6\0\0\0\0\0\0\0\0\0\0\0\0>\10\10>\10\10l\31\32\265Z\\\210')@A@@A@111898"
  "@A@@A@111G\13\13Q\16\16Q\16\16c\24\24)))))))))\40\40\40""111))))))\40\40"
  "\40\241;>G\13\13>\10\10>\10\10\0\0\0\0\0\0\0\0\0\0\0\0>\10\10>\10\10l\31"
  "\32\265Z\\\210')@A@@A@111898@A@@A@111G\13\13Q\16\16Q\16\16c\24\24)))))))"
  "))\40\40\40""111))))))\40\40\40\241;>G\13\13>\10\10>\10\10\0\0\0\0\0\0\0"
  "\0\0""5\6\6c\24\24c\24\24l\31\32\241;>\274fgv\35\36v\35\36""898IJI111111"
  "c\24\24\177\"$\221,.\221,.\177\"$Q\16\16\30\30\30\30\30\30""898111\30\30"
  "\30\30\30\30\274fg\23326Z\21\21>\10\10>\10\10""5\6\6\0\0\0\0\0\0G\13\13l"
  "\31\32l\31\32\177\"$\241;>Z\21\21IJIIJIIJIhjh898898\210')\274fg\257OQ\257"
  "OQ\250EGc\24\24))))))898@A@111111\40\40\40\177\"$Z\21\21G\13\13G\13\13>\10"
  "\10\0\0\0\0\0\0Z\21\21l\31\32l\31\32\221,.5\6\6QRQabaabaaba\201\203\202@"
  "A@@A@\257OQ\327\231\231\265Z\\\265Z\\\257OQ\210')\30\30\30\30\30\30""111"
  "@A@898898)))\40\40\40c\24\24Q\16\16Q\16\16""5\6\6\0\0\0\0\0\0Z\21\21l\31"
  "\32l\31\32\221,.5\6\6QRQabaabaaba\201\203\202@A@@A@\257OQ\327\231\231\265"
  "Z\\\265Z\\\257OQ\210')\30\30\30\30\30\30""111@A@898898)))\40\40\40c\24\24"
  "Q\16\16Q\16\16""5\6\6\0\0\0\0\0\0c\24\24v\35\36v\35\36G\13\13\0\0\0\40\40"
  "\40\40\40\40\40\40\40))))))\10\10\10\10\10\10\274fg\377\367\367\303rs\303"
  "rs\257OQ\210')\20\20\20\20\20\20\30\30\30\30\30\30\0\0\0\0\0\0\20\20\20\0"
  "\0\0G\13\13c\24\24c\24\24G\13\13\0\0\0\0\0\0c\24\24G\13\13G\13\13\0\0\0\10"
  "\10\10\20\20\20\40\40\40\40\40\40""111@A@898898\250EG\335\247\247\303rs\303"
  "rs\23326v\35\36\30\30\30\30\30\30)))\40\40\40\20\20\20\20\20\20\10\10\10"
  "\10\10\10\0\0\0Q\16\16Q\16\16Q\16\16\0\0\0\20\1\1c\24\24""5\6\6""5\6\6\0"
  "\0\0\10\10\10\40\40\40@A@@A@IJIIJI898898v\35\36\241;>\221,.\221,.c\24\24"
  "G\13\13\40\40\40\40\40\40)))111))))))\0\0\0\0\0\0\0\0\0G\13\13G\13\13c\24"
  "\24\20\1\1\20\1\1c\24\24\20\1\1\20\1\1\0\0\0\20\20\20""898hjhhjhhjhYZYQR"
  "QQRQ111Q\16\16Q\16\16Q\16\16""5\6\6\40\40\40))))))@A@YZYIJIIJI111\10\10\10"
  "\0\0\0\30\14\1\30\14\1\177\"$\20\1\1\20\1\1c\24\24\20\1\1\20\1\1\0\0\0\20"
  "\20\20""898hjhhjhhjhYZYQRQQRQ111Q\16\16Q\16\16Q\16\16""5\6\6\40\40\40)))"
  ")))@A@YZYIJIIJI111\10\10\10\0\0\0\30\14\1\30\14\1\177\"$\20\1\1\20\1\1c\24"
  "\24\30\14\1\30\14\1\0\0\0\30\30\30QRQ\201\203\202\201\203\202\222\224\223"
  "YZYIJIIJI111qsq))))))YZY\30\30\30))))))IJIqsqQRQQRQ111\0\0\0\0\0\0\10\10"
  "\10\10\10\10\177\"$\20\1\1\0\0\0c\24\24Q\16\16Q\16\16\0\0\0\30\30\30""89"
  "8QRQQRQQRQ@A@))))))\40\40\40Q\16\16c\24\24c\24\24c\24\24\40\40\40\40\40\40"
  "\40\40\40)))111111111)))\0\0\0\0\0\0c\24\24c\24\24\221,.\0\0\0\0\0\0""5\6"
  "\6c\24\24c\24\24\20\20\20\30\30\30\40\40\40""111111898)))111111898v\35\36"
  "\257OQ\257OQv\35\36""111))))))\40\40\40\40\40\40\30\30\30\30\30\30\30\30"
  "\30\0\0\0v\35\36\241;>\241;>\20\1\1\0\0\0\0\0\0""5\6\6c\24\24c\24\24\20\20"
  "\20\30\30\30\40\40\40""111111898)))111111898v\35\36\257OQ\257OQv\35\36""1"
  "11))))))\40\40\40\40\40\40\30\30\30\30\30\30\30\30\30\0\0\0v\35\36\241;>"
  "\241;>\20\1\1\0\0\0\0\0\0\0\0\0G\13\13G\13\13v\35\36\10\10\10\30\30\30\20"
  "\20\20\20\20\20)))\20\20\20""898898hjh898Q\16\16Q\16\16""898aba111111)))"
  "\30\30\30\40\40\40\40\40\40\30\30\30l\31\32\221,.\30\14\1\30\14\1\0\0\0\0"
  "\0\0\0\0\0\0\0\0\20\1\1\20\1\1""5\6\6c\24\24Q\16\16Q\16\16Q\16\16G\13\13"
  "\0\0\0IJIIJIIJI\40\40\40\0\0\0\0\0\0\40\40\40""111@A@@A@111Q\16\16Q\16\16"
  "Q\16\16c\24\24c\24\24\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\20\1\1\30\14\1\20\1\1\20\1\1\0\0\0""111QRQQRQ)))\0\0\0\0\0\0"
  "\0\0\0\0\0\0\40\40\40IJIIJI@A@\0\0\0\0\0\0\0\0\0\10\10\10\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\20\1\1\30\14\1\20\1\1"
  "\20\1\1\0\0\0""111QRQQRQ)))\0\0\0\0\0\0\0\0\0\0\0\0\40\40\40IJIIJI@A@\0\0"
  "\0\0\0\0\0\0\0\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0""898QRQQRQ\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0IJIIJI@A@\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\40\40\40QRQQRQ@A@\0\0\0\0\0\0\0\0\0\0\0\0\40\40\40YZYYZY)))\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0))))))aba\0\0\0\0\0\0\0\0\0"
  "\0\0\0YZY))))))\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0))))))aba\0\0\0\0\0\0\0\0\0\0\0\0YZY))))))\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0",
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0)))111"
  "898898\30\30\30\0\0\0""111111111\40\40\40\40\40\40\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0)))111898898\30\30\30\0\0\0""111111111\40"
  "\40\40\40\40\40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\20\20\20@A@@A@@A@QRQY"
  "ZYYZYQRQ\40\40\40QRQQRQ898111)))\40\40\40\40\40\40\30\30\30\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0))"
  ")IJIhjhhjhy{yhjhhjhhjhaba898abaaba@A@@A@111))))))\40\40\40\40\40\40\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0""111111IJIh"
  "jh\222\224\223\222\224\223\241\244\242\201\203\202qsqqsqhjh@A@qsqqsqQRQ@"
  "A@@A@111111))))))\40\40\40\40\40\40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0""111111IJIhjh\222\224\223\222\224\223\241\244\242\201\203"
  "\202qsqqsqhjh@A@qsqqsqQRQ@A@@A@111111))))))\40\40\40\40\40\40\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\40\40\40@A@@A@aba\201\203\202\211\213"
  "\212\211\213\212\211\213\212qsqhjhhjhQRQ111YZYYZYQRQQRQIJI898898111)))\30"
  "\30\30\30\30\30\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0,\4\4v\35\36"
  "\177\"$\177\"$abaqsqQRQQRQIJI111\40\40\40\40\40\40\30\30\30\20\20\20))))"
  "))\30\30\30""111@A@IJIIJI@A@\40\40\40\20\20\20\20\20\20\177\"$5\6\6\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0>\10\10l\31\32\265Z\\\265Z\\\210')@A@111111IJI@A"
  "@111111G\13\13Q\16\16c\24\24c\24\24))))))\40\40\40""111111)))\40\40\40\241"
  ";>\241;>G\13\13>\10\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0>\10\10l\31\32\265Z\\"
  "\265Z\\\210')@A@111111IJI@A@111111G\13\13Q\16\16c\24\24c\24\24))))))\40\40"
  "\40""111111)))\40\40\40\241;>\241;>G\13\13>\10\10\0\0\0\0\0\0\0\0\0""5\6"
  "\6""5\6\6c\24\24l\31\32\241;>\241;>\274fgv\35\36""898898YZY111c\24\24c\24"
  "\24\210')\23326\210')\210')Q\16\16\30\30\30@A@111111\30\30\30\274fg\2332"
  "6\23326Z\21\21>\10\10""5\6\6""5\6\6\0\0\0G\13\13G\13\13l\31\32\177\"$\241"
  ";>\241;>Z\21\21IJIIJIIJI\201\203\202898\221,.\221,.\311~\177\274fg\265Z\\"
  "\265Z\\l\31\32)))@A@@A@@A@111\40\40\40\177\"$\177\"$Z\21\21G\13\13>\10\10"
  ">\10\10\0\0\0Z\21\21Z\21\21l\31\32\221,.5\6\6""5\6\6\30\30\30\30\30\30\40"
  "\40\40\40\40\40""111\30\30\30\274fg\274fg\353\306\306\311~\177\303rs\303"
  "rs\23326\10\10\10\20\20\20\30\30\30\30\30\30\20\20\20\10\10\10\30\30\30\30"
  "\30\30c\24\24Q\16\16""5\6\6""5\6\6\0\0\0Z\21\21Z\21\21l\31\32\221,.5\6\6"
  """5\6\6\30\30\30\30\30\30\40\40\40\40\40\40""111\30\30\30\274fg\274fg\353"
  "\306\306\311~\177\303rs\303rs\23326\10\10\10\20\20\20\30\30\30\30\30\30\20"
  "\20\20\10\10\10\30\30\30\30\30\30c\24\24Q\16\16""5\6\6""5\6\6\0\0\0c\24\24"
  "c\24\24v\35\36G\13\13\0\0\0\0\0\0\30\30\30""111QRQQRQIJI)))\320\213\214\320"
  "\213\214\377\367\367\327\231\231\303rs\303rs\241;>\30\30\30""111@A@@A@11"
  "1\30\30\30\0\0\0\0\0\0G\13\13c\24\24G\13\13G\13\13\0\0\0c\24\24c\24\24G\13"
  "\13\0\0\0\10\10\10\10\10\10\30\30\30@A@QRQQRQ@A@898\265Z\\\265Z\\\361\325"
  "\325\327\231\231\257OQ\257OQ\210')\30\30\30)))898898898\30\30\30\10\10\10"
  "\10\10\10\0\0\0Q\16\16Q\16\16Q\16\16\20\1\1c\24\24c\24\24""5\6\6\0\0\0\20"
  "\20\20\20\20\20IJIabaYZYYZYIJI898\177\"$\177\"$\257OQ\241;>v\35\36v\35\36"
  "Q\16\16\40\40\40)))111111111\40\40\40\0\0\0\0\0\0\0\0\0G\13\13c\24\24c\24"
  "\24\20\1\1c\24\24c\24\24\20\1\1\0\0\0IJIIJIabahjhhjhhjhYZYQRQ111111Z\21\21"
  "Z\21\21>\10\10>\10\10\40\40\40)))@A@abaaba898111\30\30\30\30\30\30\0\0\0"
  "\30\14\1\177\"$\177\"$\20\1\1c\24\24c\24\24\20\1\1\0\0\0IJIIJIabahjhhjhh"
  "jhYZYQRQ111111Z\21\21Z\21\21>\10\10>\10\10\40\40\40)))@A@abaaba898111\30"
  "\30\30\30\30\30\0\0\0\30\14\1\177\"$\177\"$\20\1\1c\24\24c\24\24\30\14\1"
  "\0\0\0@A@@A@aba\241\244\242y{yy{yYZYIJI111111qsq)))YZYYZY\30\30\30""111Q"
  "RQqsqqsqQRQ111\30\30\30\30\30\30\0\0\0\10\10\10\177\"$\177\"$\0\0\0c\24\24"
  "c\24\24Q\16\16\0\0\0""111111IJIabaYZYYZY@A@)))\40\40\40\40\40\40Q\16\16c"
  "\24\24c\24\24c\24\24\40\40\40)))111111111111)))\30\30\30\30\30\30\0\0\0c"
  "\24\24\221,.\221,.\0\0\0""5\6\6""5\6\6c\24\24\20\20\20))))))898898898898"
  ")))111898898v\35\36\257OQv\35\36v\35\36""111)))\40\40\40))))))\40\40\40\30"
  "\30\30\0\0\0\0\0\0v\35\36\241;>\20\1\1\20\1\1\0\0\0""5\6\6""5\6\6c\24\24"
  "\20\20\20))))))898898898898)))111898898v\35\36\257OQv\35\36v\35\36""111)"
  "))\40\40\40))))))\40\40\40\30\30\30\0\0\0\0\0\0v\35\36\241;>\20\1\1\20\1"
  "\1\0\0\0\0\0\0\0\0\0G\13\13v\35\36\20\20\20\20\20\20\40\40\40\30\30\30))"
  "))))\20\20\20""898hjhhjh898Q\16\16""898898aba111)))\40\40\40\40\40\40\40"
  "\40\40\30\30\30l\31\32l\31\32\221,.\30\14\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\20\1\1""5\6\6c\24\24c\24\24Q\16\16Q\16\16G\13\13G\13\13\0\0\0YZYIJIIJI\40"
  "\40\40\0\0\0\40\40\40\40\40\40""111YZY111Q\16\16Q\16\16Q\16\16c\24\24c\24"
  "\24c\24\24\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\20\1"
  "\1\20\1\1\30\14\1\20\1\1))))))YZY@A@\40\40\40\40\40\40\0\0\0\0\0\0\0\0\0"
  "\0\0\0\40\40\40""898YZY))))))\0\0\0\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\20\1\1\20\1\1\30\14\1\20\1\1)))))"
  ")YZY@A@\40\40\40\40\40\40\0\0\0\0\0\0\0\0\0\0\0\0\40\40\40""898YZY))))))"
  "\0\0\0\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\30\30\30\30\30\30QRQ898\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\40\40\40YZY))))))\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0)))aba\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0YZY)))\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"
  "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"}
};

#endif

