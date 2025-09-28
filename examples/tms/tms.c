// vim: set ts=2 sw=2:
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

#include <tms_patterns.h>
#include <stdio.h>
#include <cpm.h>
#include <string.h>
#include <stdlib.h>
#include <tms.h>
#include "patterns.h"
//
// 16x16 ball sprite
char ball[16 * 4] = {0x07, 0x1F, 0x3E, 0x7C, 0x7F, 0xFF, 0xFF, 0xFF,
                     0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x3F, 0x1F, 0x07,
                     0xE0, 0xF8, 0x3C, 0x0E, 0x06, 0xC7, 0xE3, 0xE3,
                     0xF3, 0xF7, 0xFF, 0xFE, 0xFE, 0xFC, 0xF8, 0xE0};

char txt[64];
size_t i;
char c;
uint8_t mag = 1;
bool running;

void flush() {
  //itoa(sprites[0].x & 0xFF, txt, 10);
  sprintf(txt, "%d    ", sprites[0].x & 0xFF);
  tms_puts_xy(13, 7, txt);
  sprintf(txt, "%d    ", sprites[0].y & 0xFF);
  tms_puts_xy(13, 8, txt);
  tms_puts_xy(13, 9, "    ");
  tms_puts_xy(13, 9, (sprites[0].color & 0x80) ? "ON" : "OFF");
  tms_puts_xy(13, 10, "    ");
  tms_puts_xy(13, 10, (mag) ? "ON" : "OFF");
  tms_wait();
  tms_g1flush(tms_buf);
  tms_flush_sprites();
}

void g1() {
  tms_init_g1(GRAY, DARK_YELLOW, true, mag);
  tms_load_pat(tms_patterns, 0x400);
  tms_load_col(colors, 0x20);
  tms_load_spr(ball, 32);

  tms_fill_buf(' ');

  tms_puts_xy(9, 14, "WASD : move sprite");
  tms_puts_xy(9, 15, "C    : toggle ECB");
  tms_puts_xy(9, 16, "L    : toggle Magnified");
  tms_puts_xy(9, 17, "ESC  : quit");

  tms_puts_xy(9, 7,  "X = ");
  tms_puts_xy(9, 8,  "y = ");
  tms_puts_xy(9, 9,  "ECB ");
  tms_puts_xy(9, 10, "MAG ");


  sprites[0].y = 32; // set up the ball sprite in the middle of the screen
  sprites[0].x = 120;
  sprites[0].pattern = 0;
  sprites[0].color = LIGHT_BLUE;

  sprites[1].y = 0xD0; // disables sprite processing after the ball.

  flush();

  running = true;
  while (running) {
    c = cpm_rawio();
    if (c) {
      switch (c) {
      case 0x1B:
        running = false;
        break;
      case 'w':
        sprites[0].y--;
        break;
      case 's':
        sprites[0].y++;
        break;
      case 'a':
        sprites[0].x--;
        break;
      case 'd':
        sprites[0].x++;
        break;
      case 'c':
        sprites[0].color ^= 0x80;
        break;
      case 'l':
        mag = !mag;
        tms_set_reg(1, 0xE2 | mag);
      }
      flush();
    }
  }
}

void main() { g1(); }
