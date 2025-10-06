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

  .export _bin2hex
  .code

; void bin2hex(uint8_t value, char *buffer);
; convert 8-bit value into hexadecimal and update the buffer with the two ascii
; characters
_bin2hex:
  ld    ix,0
  add   ix,sp
  ld    e,(ix+2)
  ;ld    d,(ix+3) ; val in e (don't need d)
  ld    l,(ix+4)
  ld    h,(ix+5) ; *buf in hl
  inc   hl
  ld    a,e
  call  num2
  dec   hl
  ld    a,e
num1:
  rra
  rra
  rra
  rra
num2:
  and   0x0f
  add   a,0x90
  daa
  adc   a,0x40
  daa
  ld    (hl),a
  ret


