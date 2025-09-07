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


void tms_init_text(uint8_t fg, uint8_t bg)
{
  tms_name_tbl = 0x800;
  tms_n_tbl_len = 960;
  tms_color_tbl = 0x0;      // not used
  tms_c_tbl_len = 0x0;  // not used 
  tms_patt_tbl = 0x0;
  // tms_sp_attr_tbl = 0x0; // not used
  // tms_sp_patt_tbl = 0x0; // not used
  tms_set_reg(0, 0x00);
  tms_set_reg(1, 0xF0); //16K, enable display, enable int
  tms_set_reg(2, 0x02);
  //tms_set_reg(3, 0x00); // not used
  tms_set_reg(4, 0x00);
  //tms_set_reg(5, 0x00); // not used
  //tms_set_reg(6, 0x00); // not used
  tms_set_reg(7, ((fg & 0x0F)<<4) | (bg & 0x0F));
  tms_buf = malloc(960);
  memset(tms_buf, 0, 960);
}

