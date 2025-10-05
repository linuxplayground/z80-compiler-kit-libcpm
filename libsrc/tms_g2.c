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

#include <stdbool.h>
#include <tms.h>
#include <string.h>
#include <stdlib.h>


void tms_init_g2(uint8_t fg, uint8_t bg, bool largesp, bool mag)
{
  uint8_t sprite_flags = 0;
  sprite_flags |= largesp << 1;
  sprite_flags |= mag << 0;

  tms_name_tbl = 0x3800;
  tms_n_tbl_len = 0x300;
  tms_color_tbl = 0x2000;
  tms_c_tbl_len = 0x1800;
  tms_patt_tbl = 0x0;
  tms_sp_attr_tbl = 0x3B00;
  tms_sp_patt_tbl = 0x1800;

  tms_mode = MODE_G2;

  tms_set_reg(0, 0x02);
  tms_set_reg(1, 0xE0|sprite_flags); //16K, enable display, enable int + sprite settings
  tms_set_reg(2, 0x0E);
  tms_set_reg(3, 0xFF);
  tms_set_reg(4, 0x03);
  tms_set_reg(5, 0x76);
  tms_set_reg(6, 0x03);
  tms_set_reg(7, bg & 0xF);
  tms_buf = malloc(0x300);
  memset(tms_buf, 0, 0x300);
  tms_init_sprites();
}

void tms_init_bitmap_mode()
{
  size_t i = 0;
  // Write 0-255 into the name table 3 times in a row.
  tms_w_addr(tms_name_tbl);
  for (i=0; i<256; ++i)
  {
    tms_put(i);
  }
  tms_w_addr(tms_name_tbl + 256);
  for (i=0; i<256; ++i)
  {
    tms_put(i);
  }
  tms_w_addr(tms_name_tbl + 512);
  for (i=0; i<256; ++i)
  {
    tms_put(i);
  }

  // Fill the pattern table with zeros
  tms_w_addr(tms_patt_tbl);
  for (i = 0; i<0x1800; ++i)
    tms_put(0);

  // Fill the color table with zeros
  tms_w_addr(tms_color_tbl);
  for (i = 0; i<0x1800; ++i)
    tms_put(0);
}

void tms_plot_g2(uint8_t x, uint8_t y, uint8_t fg, uint8_t bg)
{
    uint16_t offset = 8 * (x / 8) + y % 8 + 256 * (y / 8);
    uint8_t pixel;
    uint8_t color;

    tms_r_addr(tms_patt_tbl + offset);
    pixel = tms_get();

    tms_r_addr(tms_color_tbl + offset);
    color = tms_get();

    if (fg != 0) {

      pixel |= 0x80 >> (x % 8); // Set bit a "1"
      color = (color & 0x0F) | (fg << 4);
    } else {

      pixel &= ~(0x80 >> (x % 8)); // Set bit as "0"
      color = (color & 0xF0) | (bg & 0x0F);
    }

    tms_w_addr(tms_patt_tbl + offset);
    tms_put(pixel);

    tms_w_addr(tms_color_tbl + offset);
    tms_put(color);
  }

