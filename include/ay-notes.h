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
* https://github.com/linuxplayground/z80-retro-libcpm.git
*
*****************************************************************************
*/

/*
 * These are the course and fine register values for the 3 tone channels.
 * The indexes of the array are the piano key numbers.
 *
 * The play_note_function takes the index for the note you want to play and
 * selects the register values from these arrays.
 *
 * The worksheet for these values is in the docs directory.
 */

#ifndef _AYNOTES
#define _AYNOTES

extern unsigned char notes_course[89];
extern unsigned char notes_fine[89];

#endif //_AYNOTES
