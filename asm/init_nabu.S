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
; Assembly routines for dealing with TMS VDP Registers
;
;****************************************************************************


#ifdef NABU

#include "io.h"
#include "nabu_constants.h"

  .export init_nabu
  .export _lastKbIntVal
  .export _kbdBufReadPos
  .export _kbdBufWritePos
  .export _joySt0
  .export _joySt1
  .export _joySt2
  .export _joySt3
  .export _kbdBuffer
  .export _tms_is_ready
  .export _tms_status

  .code

;===============================================================================
; Read a register from the AY-3-8910
; INPUT: A = Register to read
; OUTPUT: A = value
; CLOBBERS: AF
;===============================================================================
ay_read:
  out   (IO_AYREG),a
  in    a,(IO_AYDATA)
  ret

;===============================================================================
; Write a value to the AY-3-8910 register
; INPUT: B = Register to write to, C = value to write
; OUTPUT: void
; CLOBBERS: none
;===============================================================================
ay_write:
  ld    a,b
  out   (IO_AYREG),a
  ld    a,c
  out   (IO_AYDATA),a
  ret


init_nabu:
  ;Turn off the rom
  ld    a,0x03 ;CONTROL_ROMSEL|CONTROL_VDOBUF
  out   (IO_CONTROL),a
  di    ; disable interrupts

  im    2

  ld    hl, isrKeyboard
  ld    (0xff00+4), hl

  ld    hl, isrVdp
  ld    (0xff00+6), hl

  ld    b,0x07
  ld    c,01111111b
  call  ay_write        ; configure PORTA for writing and port B for reading

  ld    a,IO_PORTA
  call  ay_read         ; get the current interrupt mask from AY Port A
  or    0x30; INT_MASK_KEYBOARD|INT_MASK_VDP
  ld    c,a
  ld    b,IO_PORTA
  call  ay_write
  xor   a
  ld    (_kbdBufReadPos),a
  ld    (_kbdBufWritePos),a
  ei    ; enable interrupts
  ret

isrVdp:
  push  af
  in    a,(IO_TMSREG)
  ld    (_tms_status),a
  ld    a,0x01
  ld    (_tms_is_ready), a
  pop   af
  ei
  reti

isrKeyboard:
        push	bc
        push	de
        push	hl
        push	af
        push	iy

        ld	iy,0
        in	a,(IO_KEYBOARD)
        ld	c,a
        sub	0x80
        jr	c,isrkb_1
        ld	a,0x83
        sub	c
        jr	c,isrkb_1
        ld	iy,_lastKbIntVal
        ld	(iy+0),c
        jr	isrkb_exit
isrkb_1:
        ld	a,c
        sub	0x90
        jr	c,isrkb_2
        ld	a,0x95
        sub	c
        jr	nc,isrkb_exit
isrkb_2:
        ld	a,(_lastKbIntVal+0)
        cp	0x80
        jr	z,isrkb_3
        cp	0x81
        jr	z,isrkb_4
        cp	0x82
        jr	z,isrkb_5
        cp	0x83
        jr	z,isrkb_6
        jr	isrkb_7
isrkb_3:
        ld	iy,_lastKbIntVal
        ld	(iy+0),0x00
        ld	hl,_joySt0
        ld	(hl),c
        jr	isrkb_exit
isrkb_4:
        ld	iy,_lastKbIntVal
        ld	(iy+0),0x00
        ld	hl,_joySt1
        ld	(hl),c
        jr	isrkb_exit
isrkb_5:
        ld	iy,_lastKbIntVal
        ld	(iy+0),0x00
        ld	hl,_joySt2
        ld	(hl),c
        jr	isrkb_exit
isrkb_6:
        ld	iy,_lastKbIntVal
        ld	(iy+0),0x00
        ld	hl,_joySt3
        ld	(hl),c
        jr	isrkb_exit
isrkb_7:					; not a joystick. Add key press to buffer
        ld	hl,_kbdBuffer+0			; increment buffer write position.
        ld	de,(_kbdBufWritePos)
        ld	d,0
        add	hl,de
        ld	(hl),c
        ld	a,(_kbdBufWritePos)
        inc	a
        ld	(_kbdBufWritePos),a
isrkb_exit:
        pop	iy
        pop	af
        pop	hl
        pop	de
        pop	bc
        ei
  reti

origint:                  .ds 1
_lastKbIntVal:            .ds 1
_kbdBufReadPos:           .ds 1
_kbdBufWritePos:          .ds 1
_joyStatus:               .ds 2
_kbdBuffer:               .ds 0xff
_joySt0:                  .ds 1
_joySt1:                  .ds 1
_joySt2:                  .ds 1
_joySt3:                  .ds 1

_tms_is_ready:            .ds 1
_tms_status:              .ds 1

#endif
