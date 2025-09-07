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


char *tms_buf = NULL;

uint16_t tms_name_tbl = 0;    // REG: 2
uint16_t tms_color_tbl = 0;   // REG: 3
uint16_t tms_patt_tbl = 0;    // REG: 4
uint16_t tms_sp_attr_tbl = 0; // REG: 5
uint16_t tms_sp_patt_tbl = 0; // REG: 6

uint16_t tms_n_tbl_len = 0;
uint16_t tms_c_tbl_len = 0;

void tms_load_pat(char *pattern, size_t len)
{
  char *p = pattern;
  char *e = pattern  + len;
  tms_w_addr(tms_patt_tbl);
  do {
    tms_put(*p);
  } while (p++ < e);
}

void tms_load_col(char *color, size_t len)
{
  char *p = color;
  char *e = color  + len;
  tms_w_addr(tms_color_tbl);
  do {
    tms_put(*p);
  } while (p++ < e);
}

