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
#include <cpm.h>
#include "patterns.h"

char txt[64];
size_t i;
char c;

void g1()
{
  tms_init_g1(GRAY, DARK_YELLOW, true, false);
  tms_load_pat(patterns, 0x400);
  tms_load_col(colors, 0x20);

  tms_print_xy(10,2,"Hello, World!");
  tms_print_xy(10,4, "THAT'S COOL!");
  tms_wait();
  tms_g1flush(tms_buf);
}

void mc()
{
  tms_init_mc(GRAY, DARK_YELLOW, true, false);
  tms_plot_mc( 0, 0, LIGHT_GREEN);
  tms_plot_mc( 0,47, MEDIUM_RED);
  tms_plot_mc(63, 0, DARK_GREEN);
  tms_plot_mc(63,47, LIGHT_BLUE);
  tms_wait();
  tms_mcflush(tms_buf);
}

void main()
{
  g1();
}
