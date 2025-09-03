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
; https://github.com/linuxplayground/z80-retro-cpmlib.git
;
; Assembly routines for dealing with TMS VDP Registers
;
;****************************************************************************

  .export _tms_set_reg
  .export _tms_set_wr_ad
  .export _tms_set_rd_ad
  .export _IO_TMSRAM
  .export _IO_TMSREG

_IO_TMSRAM equ 0x80
_IO_TMSREG equ 0x81

  .code

;void tms_set_reg(uint8_t reg, uint8_t val);
_tms_set_reg:
  push  bc  ; preserve bc for compilerkit
  pop   de
  push  de  ; e = val
            ; hl = reg
  ld    c,_IO_TMSREG
  out   (c),e
  ld    a,l
  or    0x80
  out   (c),a
  pop   bc
  ret

;void tms_set_wr_ad(uint16_t addr);
_tms_set_wr_ad:
  push  bc  ; preserve bc for compilerkit
  ld    c,_IO_TMSREG
  out   (c),l
  ld    a,h
  or    0x40
  out   (c),a
  pop   bc
  ret

;void tms_set_rd_ad(uint16_t addr);
_tms_set_rd_ad:
  push  bc  ; preserve bc for compilerkit
  ld    c,_IO_TMSREG
  out   (c),l
  out   (c),h
  pop   bc
  ret
