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
  pop   bc  ; return
  pop   de  ; val
  pop   hl  ; pointer to buffer to write into

  push  hl
  push  de
  push  bc

  ld    a,e
  srl   a
  srl   a
  srl   a
  srl   a
  call  hexdump_nib
  ld    a,e
  and   0x0f

hexdump_nib:
  add   a,0x30
  cp    0x3A    ; '9' + 1
  jp    m,hexdump_num
  add   a,0x07  ; 'A' - '9' - 1
hexdump_num:
  ld    (hl),a
  inc   hl
  ret


