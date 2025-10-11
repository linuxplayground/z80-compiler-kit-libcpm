/*
*****************************************************************************
*
*    Copyright (C) 2025 David Latham
*
*    This library is free software; you can redistribute it and/or
*    modify it under the terms of the GNU Lesser General Public
*    License as published by the Free Software Foundation; either
*    version 2.1 of the License, or (at your option) any later version.
*
*    This library is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*    Lesser General Public License for more details.
*
*    You should have received a copy of the GNU Lesser General Public
*    License along with this library; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
*    USA
*
* https://github.com/linuxplayground/z80-compiler-kit-libcpm
*
*****************************************************************************
*/

#include <stdint.h>
#include <stdbool.h>

extern uint8_t kbdBufReadPos;
extern uint8_t kbdBufWritePos;
extern uint8_t kbdBuffer[256];
extern uint8_t joySt0;
extern uint8_t joySt1;
extern uint8_t joySt2;
extern uint8_t joySt3;


bool nb_kbhit()
{
  return ~(kbdBufReadPos==kbdBufWritePos);
}

char nb_getc()
{
  return kbdBuffer[kbdBufReadPos++];
}

uint8_t nb_getj(uint8_t j)
{
  switch (j) {
    case 0: return joySt0; break;
    case 1: return joySt1; break;
    case 2: return joySt2; break;
    case 3: return joySt3; break;
    default: break;
  }
}
