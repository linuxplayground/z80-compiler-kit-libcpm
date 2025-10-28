; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;
;    Copyright (C) 2025 David Latham
;
;    This library is free software; you can redistribute it and/or
;    modify it under the terms of the GNU Lesser General Public
;    License as published by the Free Software Foundation; either
;    version 2.1 of the License, or (at your option) any later version.
;
;    This library is distributed in the hope that it will be useful,
;    but WITHOUT ANY WARRANTY; without even the implied warranty of
;    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
;    Lesser General Public License for more details.
;
;    You should have received a copy of the GNU Lesser General Public
;    License along with this library; if not, write to the Free Software
;    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
;    USA
;
; https://github.com/linuxplayground/z80-compiler-kit-libcpm
;
;****************************************************************************
#include "io.h"

  .export _joy

  .code
; uint8_t joy(uint8_t i);
_joy:
#ifdef NABU
  ld  a,l
  or  a
  ld  hl,IO_JOY1  ; relies on J2, J3 and J4 all in sequence at special ram
  add a,l         ; addresses
  ld  a,(hl)
  xor 0xFF
  or  0xE0
  ld  l,a
  ld  h,0
  ret

#else

  ld  a,l
  or  a
  jr  nz,joy1
  ld  c,IO_JOY0
  jr  readjoy
joy1:
  ld  c,IO_JOY1
readjoy:
  in  a,(c)
  ld  l,a
  ld  h,0
  ret

#endif
