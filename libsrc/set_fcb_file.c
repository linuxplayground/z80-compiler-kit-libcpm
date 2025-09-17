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
* https://github.com/linuxplayground/z80-retro-libcpm.git
*
*****************************************************************************
*/

#include <cpm.h>
#include <stddef.h>
#include <string.h>

bool set_fcb_file(FCB *fcb, const char *filename) {
  uint8_t i;
  char *dot;

  memset(fcb, 0, sizeof(FCB));

  if ( filename[1] == ':'){
    i = toupper(filename[0]) - 'A';
    if ( (i >= 0) || (i<=15))
      fcb->dr = i;
    else
      return false;
  } else {
    fcb->dr = 0;
  }
  dot = strchr(filename, '.');

  if (dot == NULL) return false;

  for (i=0; i<8; ++i) {
    if ((filename[i]) && ((filename + i) < dot)) {
      fcb->f[i] = toupper(filename[i]);
    } else {
      fcb->f[i] = 0x20;
    }
  }

  if (dot) {
    dot ++;
    for (i=0; i<3; ++i) {
      if (dot[i]) {
        fcb->t[i] = toupper(dot[i]);
      } else {
        fcb->t[i] = 0x20;
      }
    }
  } else {
    memset(fcb->t, 0x20, 3);
  }
  return true;
}

