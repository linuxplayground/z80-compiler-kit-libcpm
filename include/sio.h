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

#ifndef _SIO_H
#define _SIO_H

#include <stdbool.h>

/*
 * Raw SIO Interface to channel A for faster access to serial IO.
 *
 * Fetch a single character from the serial input.
 * Blocks until a character is available.
 */
extern char chin();

/*
 * Output a single character to the serial output.
 * Blocks until output channel is ready
 */
extern void chout(char c);

/* Returns true if a key was pressed
 */
extern bool cstat();

#endif //_SIO_H

