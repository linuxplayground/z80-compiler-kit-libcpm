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
  .export _tms_w_addr
  .export _tms_r_addr
  .export _tms_put
  .export _tms_get
  .export _tms_wait
  .export _tms_g1flush
  .export _tms_g2flush
  .export _tms_mcflush
  .export _tms_txtflush

  .export _IO_TMSRAM
  .export _IO_TMSREG
  .export _IO_JOY0
  .export _IO_JOY1

_IO_TMSRAM equ 0x80
_IO_TMSREG equ 0x81
_IO_JOY0   equ 0xA8
_IO_JOY1   equ 0xA8

  .code

;void tms_set_reg(uint8_t reg, uint8_t val);
_tms_set_reg:
  pop   bc  ; return
  pop   hl  ; reg
  pop   de  ; val

  push  de
  push  hl
  push  bc

  ld    c,_IO_TMSREG
  out   (c),e
  ld    a,l
  or    0x80
  out   (c),a
  ret

;void tms_set_w_addr(uint16_t addr);
_tms_w_addr:
  ld    c,_IO_TMSREG
  out   (c),l
  ld    a,h
  or    0x40
  out   (c),a
  ret

;void tms_r_addr(uint16_t addr);
_tms_r_addr:
  ld    c,_IO_TMSREG
  out   (c),l
  out   (c),h
  ret

; void tms_put(uint8_t c);
_tms_put:
  ld    a,l
  out   (_IO_TMSRAM),a
  push  hl
  pop   hl
  push  hl
  pop   hl
  push  hl
  pop   hl
ret

; uint8_t tms_get();
_tms_get:
  in    a,(_IO_TMSRAM)
  ld    l,a
  ld    h,0
  push  hl
  pop   hl
  push  hl
  pop   hl
  push  hl
  pop   hl
  ret

; uint8_t tms_wait();
_tms_wait:
  in    a,(_IO_JOY0)   ; read the /INT status via bodge wire 
  and   0x02           ; check U6, pin 4 (D1)
  jp    nz,_tms_wait
  in    a,(_IO_TMSREG) ; read the VDP status register to reset the IRQ
  ret

; Make sure that tms_wait is called immediately prior to thes flush routines.

; extern void tms_g1flush(char *buf);
_tms_g1flush:
  ld    de, 0x1400
  ld    bc, 0x300
  jp    tms_write_fast

; extern void tms_g2flush(char *buf);
_tms_g2flush:
  ld    de, 0x3800
  ld    bc, 0x300
  jp    tms_write_fast

; extern void tms_g2flush(char *buf);
_tms_txtflush:
  ld    de, 0x800
  ld    bc, 960
  jp    tms_write_fast

; void tms_mcflush(char *buf);
; make sure to run tms_wait first
_tms_mcflush:
  ld    de,0x800
  ld    bc,0x600
  ;jp    tms_write_fast
  ; FALL THROUGH
tms_write_fast:
  ex    de,hl
  call  _tms_w_addr
  ex    de,hl
  ld    d,b
  ld    e,c
  ld    c,_IO_TMSRAM
; goldilocks
  ld    b,e
  inc   e
  dec   e
  jr    z,tms_wrfastlp
  inc   d
tms_wrfastlp:
  outi
  jp    nz,tms_wrfastlp
  dec   d
  jp    nz,tms_wrfastlp
  ret

