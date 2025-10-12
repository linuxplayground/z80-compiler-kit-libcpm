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

#ifndef _NABU_H
#define _NABU_H

#include <stdint.h>
#include <stdbool.h>

/* NOTE: For these functions to work the keyboar interrupt service routine must
 * have been setup.  I have an outstanding request with DJ Sures who maintains
 * CloudCPM to ask if the joystick status can be returned by the bios into
 * special / magic addresses.  That way we can continue to use CPM for keybaord
 * routines and still access joystick data.
 */

/* Return true if a key is pressed, false otherwise */
bool nb_kbhit();

/* Returns the last characater in the kbd buffer.  If no characater then
 * returns 0
 */
char nb_getc();

#endif //_NABU_H

