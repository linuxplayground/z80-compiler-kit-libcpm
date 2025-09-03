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

#include <stdbool.h>
#include <core.h>
#include <tms.h>
#include <stddef.h>
#include <string.h>
#include <malloc.h>

char *tms_buf = NULL;

uint16_t tms_name_tbl = 0;    // REG: 2
uint16_t tms_color_tbl = 0;   // REG: 3
uint16_t tms_patt_tbl = 0;    // REG: 4
uint16_t tms_sp_attr_tbl = 0; // REG: 5
uint16_t tms_sp_patt_tbl = 0; // REG: 6

void tms_init(uint8_t mode, uint8_t fg, uint8_t bg, bool largesp, bool mag) {

  uint8_t sprite_flags = 0;
  sprite_flags |= largesp << 1;
  sprite_flags |= mag << 0;

  switch (mode) {
  case MODE_G1:
    tms_name_tbl = 0x1400;
    tms_color_tbl = 0x2000;
    tms_patt_tbl = 0x800;
    tms_sp_attr_tbl = 0x1000;
    tms_sp_patt_tbl = 0x0;
    tms_set_reg(0, 0x0);
    tms_set_reg(1, 0xE0|sprite_flags); //16K, enable display, enable int + sprite settings
    tms_set_reg(2, 0x05);
    tms_set_reg(3, 0x80);
    tms_set_reg(4, 0x01);
    tms_set_reg(5, 0x20);
    tms_set_reg(6, 0x00);
    tms_set_reg(7, (fg<<4) | bg);
    tms_buf = malloc(768);
    memset(tms_buf, 0, 768);
    break;

  case MODE_G2:
    tms_name_tbl = 0x3800;
    tms_color_tbl = 0x2000;
    tms_patt_tbl = 0x0;
    tms_sp_attr_tbl = 0x3B00;
    tms_sp_patt_tbl = 0x1800;
    tms_set_reg(0, 0x02);
    tms_set_reg(1, 0xE0|sprite_flags); //16K, enable display, enable int + sprite settings
    tms_set_reg(2, 0x0E);
    tms_set_reg(3, 0xFF);
    tms_set_reg(4, 0x03);
    tms_set_reg(5, 0x76);
    tms_set_reg(6, 0x03);
    tms_set_reg(7, (fg<<4) | bg);
    tms_buf = malloc(768);
    memset(tms_buf, 0, 768);
    break;
  case MODE_MC:
    tms_name_tbl = 0x1400;
    // tms_color_tbl = 0x0; // not used
    tms_patt_tbl = 0x800;
    tms_sp_attr_tbl = 0x1000;
    tms_sp_patt_tbl = 0x0;
    tms_set_reg(0, 0x02);
    tms_set_reg(1, 0xE8|sprite_flags); //16K, enable display, enable int + sprite settings
    tms_set_reg(1, 0xE8);
    tms_set_reg(2, 0x05);
    //tms_set_reg(3, 0x00); // not used
    tms_set_reg(4, 0x01);
    tms_set_reg(5, 0x20);
    tms_set_reg(6, 0x00);
    tms_set_reg(7, (fg<<4) | bg);
    tms_buf = malloc(768*2);
    memset(tms_buf, 0, 768*2);
    break;
  case MODE_TEXT:
    tms_name_tbl = 0x800;
    tms_color_tbl = 0x0; // not used
    tms_patt_tbl = 0x0;
    // tms_sp_attr_tbl = 0x0; // not used
    // tms_sp_patt_tbl = 0x0; // not used
    tms_set_reg(0, 0x00);
    tms_set_reg(1, 0xE0); //16K, enable display, enable int
    tms_set_reg(2, 0x02);
    //tms_set_reg(3, 0x00); // not used
    tms_set_reg(4, 0x00);
    //tms_set_reg(5, 0x00); // not used
    //tms_set_reg(6, 0x00); // not used
    tms_set_reg(7, (fg<<4) | bg);
    tms_buf = malloc(960);
    memset(tms_buf, 0, 960);
    break;
  default:
    exit(-1); // provided video mode is unsupported
  }
}
