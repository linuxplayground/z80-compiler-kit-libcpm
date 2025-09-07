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

#include <tms.h>
#include <string.h>


char txt[64];
size_t i;
char c;

void g1()
{
  tms_init(MODE_G1, GRAY, DARK_YELLOW, true, false);

  tms_w_addr(tms_patt_tbl);
  tms_put(0);
  tms_put(0);
  tms_put(0);
  tms_put(0);
  tms_put(0);
  tms_put(0);
  tms_put(0);
  tms_put(0);

  tms_put(0xF0);
  tms_put(0xF0);
  tms_put(0xF0);
  tms_put(0xF0);
  tms_put(0x0F);
  tms_put(0x0F);
  tms_put(0x0F);
  tms_put(0x0F);

  tms_w_addr(tms_name_tbl);
  for (i=0; i<768; ++i) {
    tms_put(0);
  }

  tms_w_addr(tms_name_tbl);
  tms_put(1);

  tms_w_addr(tms_color_tbl);
  tms_put(0x21);
}

void mc()
{
  tms_init(MODE_MC, GRAY, DARK_YELLOW, true, false);
  tms_plot_mc( 0, 0, LIGHT_GREEN);
  tms_plot_mc( 0,47, MEDIUM_RED);
  tms_plot_mc(63, 0, DARK_GREEN);
  tms_plot_mc(63,47, LIGHT_BLUE);
  tms_wait();
  tms_mcflush(tms_buf);
}

void main()
{
  mc();
}
