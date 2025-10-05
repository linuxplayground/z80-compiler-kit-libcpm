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
* https://github.com/linuxplayground/z80-compiler-kit-libcpm
*
*****************************************************************************
*/

#include <ay-3-8910.h>
#include <ay-notes.h>
#include <stdint.h>

void ay_play_note_delay(uint8_t key, uint8_t channel, uint16_t delay) {
  // channel must be 0, 1 or 2 for A, B or C
  if (channel > 2)
    return;

  // there are only 88 keys on the keyboard
  if (key > 88)
    return;

  // The zeroth key is for silence. Set the volume of channel to 0
  if (key == 0) {
    ay_write(AY_VOLUME_A + channel, 0);
    return;
  }

  // Write the note values to the register.
  ay_write(channel * 2, notes_fine[key]);
  ay_write(channel * 2 + 1, notes_course[key]);

  // only add delay if delay > 0
  if (delay > 0) {
    ay_write(AY_VOLUME_A + channel, 0x1F);
    ay_write(AY_ENVELOPE_C, delay >> 8);
    ay_write(AY_ENVELOPE_F, delay & 0xFF);
    ay_write(AY_ENVELOPE_SHAPE, AY_ENV_SHAPE_FADE_OUT);
  }
}
