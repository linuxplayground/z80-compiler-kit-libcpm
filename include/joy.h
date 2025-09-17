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

#ifndef _JOY_H
#define _JOY_H

#include <stdint.h>

#define JOY_MAP_LEFT      0x04//0b00000100
#define JOY_MAP_RIGHT     0x20//0b00100000
#define JOY_MAP_UP        0x80//0b10000000
#define JOY_MAP_DOWN      0x40//0b01000000
#define JOY_MAP_BUTTON    0x01//0b00000001


/*
 * Read the value of one of the joysticks
 *
 * i == 0 -->> J3 (Z80-Retro! 2063 VDP / Atari Joystick daughter board)
 * i >= 1 -->> J4 (Z80-Retro! 2063 VDP / Atari Joystick daughter board)
 */
extern uint8_t joy(uint8_t i);

#endif //_JOY_H

