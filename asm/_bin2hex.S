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
  ld    hl,2    ; skip past the return address
  add   hl,sp   ; hl points to the first parameter
  ld    a,(hl)  ; value
  inc   hl      ; inc hl to the next parameter
  inc   hl
  ld    e,(hl)  ; low byte of *buf in e
  inc   hl
  ld    d,(hl)  ; high byte of *buf in d
  ex    de,hl   ; hl = *buf

  ld    e,a     ; save value in e
  inc   hl      ; increment buf to print low nibble
  call  num2    ; calculate and print low nibble
  dec   hl
  ld    a,e     ; restore value from e
                ; fall through
num1:           ; shift high nibble down to low nibble
  rra
  rra
  rra
  rra
num2:           ; magic hex converion.
  and   0x0f
  add   a,0x90
  daa
  adc   a,0x40
  daa
  ld    (hl),a  ; save ascii char in *buf
  ret


