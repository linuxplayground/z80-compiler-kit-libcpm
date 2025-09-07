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

#ifndef _TMS_H
#define _TMS_H

#include <stdint.h>
#include <stdbool.h>

#define TMS_COLLISION_BIT 1 << 5
#define TMS_5TH_SPRITE_BIT 1 << 4

enum {
  TRANSPRAENT=0
  BLACK
  MEDIUM_GREEN
  LIGHT_GREEN
  DARK_BLUE
  LIGHT_BLUE
  RARK_RED
  CYAN
  MEDIUM_RED
  LIGHT_RED
  DARK_YELLOW
  LIGHT_YELLOW
  DARK_GREEN
  MAGENTA
  GRAY
  WHITE
};

enum {
  MODE_G1 = 0,
  MODE_G2,
  MODE_MC,
  MODE_TEXT
};

/* global pointer to the framebuffer */
extern char *tms_buf;

/* variables holding the base addresses of VDP memory tables */
extern uint16_t tms_name_tbl;      // REG: 2
extern uint16_t tms_color_tbl;     // REG: 3
extern uint16_t tms_patt_tbl;      // REG: 4
extern uint16_t tms_sp_attr_tbl;   // REG: 5
extern uint16_t tms_sp_patt_tbl;   // REG: 6

/* Initialize the VDP in one of the modes */
void tms_init(uint8_t mode, uint8_t fg, uint8_t bg, bool largesp, bool mag);

/* Set a vdp register */
extern void tms_set_reg(uint8_t reg, uint8_t val);

/* waits for a VSYNC interrupt from the VDP and retuns the value of the VDP
 * status register
 */
extern uint8_t tms_wait();

/* set the vdp memory write address */
extern void tms_r_addr(uint16_t addr);

/* set the vdp memory read address */
extern void tms_w_addr(uint16_t addr);

/* write a single byte to VRAM at current address */
extern void tms_put(uint8_t c);

/* read a single byte from VRAM at current address */
extern uint8_t tms_get();

/* plot a single fat pixel in multi color mode */
void tms_plot_mc(uint8_t x, uint8_t y, uint8_t c);

/* wait for vsync and return status of vdp */
extern uint8_t tms_wait();

/* flush the MC pattern table from a buffer to the VDP */
extern void tms_mcflush(char *buf);

#endif //_TMS_H
