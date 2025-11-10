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

  .export _exit
  .code
_exit:
  ld    hl,2
  add   hl,sp
  ld    a,(hl)
  or    a
  jp    z,0               ; warmboot without printing if exit(0);

; Assume the unsigned char to print is in register A
PRINT_HEX:
  push  af                ; save a and flags
  srl   a                 ; shift high nibble to low position
  srl   a
  srl   a
  srl   a
  call  nibble_to_ascii   ; convert and print high nibble

  pop   af                ; restore a and flags
  and   0x0f              ; isolate low nibble
  call  nibble_to_ascii   ; convert and print low nibble

  jp    0                 ; done - warmboot.

nibble_to_ascii:
  cp    0xa               ; compare with 10
  jr    c, is_digit       ; if less than 10, it's a digit
  add   a, 'a' - 0xa      ; convert to a-f (uppercase)
  jr    print_char
is_digit:
  add   a, '0'            ; convert to 0-9
print_char:
  ld    l,a
  push  hl
  call  _cpm_conout
  pop   hl
  ret

