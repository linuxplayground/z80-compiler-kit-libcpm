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
* https://github.com/linuxplayground/z80-compiler-kit-libcpm
*
*****************************************************************************
*/

/* Using a different translation unit for sprites in case they are not needed.
 *  In which case, this code won't be linked into the final executable.
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <tms.h>
#include <io.h>

Sprite sprites[32] = {
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 },
  { 0xD0, 0, 0, 0 }
};

void tms_flush_sprites() {
  uint8_t i;
  tms_w_addr(tms_sp_attr_tbl);
  for (i = 0; i < 32; ++i) {
    tms_put(sprites[i].y & 0xFF);
    tms_put(sprites[i].x & 0xFF);
    tms_put(sprites[i].pattern);
    tms_put(sprites[i].color);
    if (sprites[i].y == 0xD0)
      break;
  }
}

void tms_init_sprites() {
  sprites[0].y = 0xD0;
  sprites[0].x = 0x00;
  sprites[0].pattern = 0x00;
  sprites[0].color = 0x80;
  tms_flush_sprites();
}

void tms_disable_spr(uint8_t index) {
  sprites[index].y = 192;       // hide below bottom of screen
  sprites[index].color |= 0x80; // ECB set to hide sprite off bottom of screen
}

void tms_load_spr(char *sprites, size_t len) {
  char *p = sprites;
  char *e = sprites + len;
  tms_w_addr(tms_sp_patt_tbl);
  do {
    tms_put(*p);
  } while (p++ < e);
}
