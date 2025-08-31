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

static void my_strrev(char *str) {
  uint16_t len = strlen(str);
  uint16_t i, j;
  for (i = 0, j = len - 1; i < j; i++, j--) {
    uint8_t a = str[i];
    str[i] = str[j];
    str[j] = a;
  }
}

int8_t itoa(uint16_t val, char *str, uint8_t len, uint8_t base)
{
  uint16_t sum = val;
  uint8_t i = 0;
  uint8_t digit;

  if (len == 0)
    return -1;
  do {
    digit = sum % base;
    if (digit < 0xA)
      str[i++] = '0' + digit;
    else
      str[i++] = 'A' + digit - 0xA;
    sum /= base;
  } while (sum && (i < (len-1)));
  str[i] = '\0';
  my_strrev(str);
  return 0;
}
