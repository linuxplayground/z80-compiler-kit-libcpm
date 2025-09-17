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
* https://github.com/linuxplayground/z80-retro-cpmlib.git
*
*****************************************************************************
*/

#include "string.h"
#include <stdint.h>
#include <stdlib.h>

static char buf[8];

char *_uitoa(uint16_t i, uint8_t radix) {
  char *p = buf + sizeof(buf);
  int c;
  uint8_t d;

  *--p = '\0';
  do {
    d = i % radix;
    if (d < 0xA)
      *--p = '0' + d;
    else
      *--p = 'A' + d - 0xA;
    i /= radix;
  } while (i);
  return p;
}

void uitoa(uint16_t val, char *str) {
  strcpy(str, _uitoa(val, 10));
}

// We don't know if the string passed to us is long enough, so just copy ours anyway.
void itoa(int16_t val, char *str, uint8_t radix) {
  char *p;
  uint8_t flg = 0;
  if (val < 0 && radix == 10) {
    flg++;
    val = -val;
  }
  p = _uitoa(val, radix);
  if (p && flg) *--p = '-';
  strcpy(str, p);
}
