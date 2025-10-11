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
  push  af
  push  bc
  in    a,(IO_KEYBOARD) ; a=inkey
  ld    b,a         ; save inkey
  cp    0x80
  jr    nc,isrKb1   ; if a >= 0x80 then check if A <= 0x83
  jp    isrKbJoy    ; else go to joystick checks
isrKb1:
  cp    0x84
  jr    nc,isrKbJoy ; if a >= 0x84 then joystick
                    ; else
  ld    (_lastKbIntVal),a ; save inkey into lastKbIntVal
  jp    isrKbExit   ; return from interrupt
isrKbJoy:
  ; if inkey < 0x90 || inkey > 0x95
  ld    a,b         ; a=inkey
  cp    0x90        ; a < 0x90
  jr    c,isrKbJoy1
  cp    0x96        ; a >= 0x96 (> 0x95)
  jr    nc,isrKbJoy1
  jp    isrKbExit     ; else exit
isrKbJoy1:
  ld    a,(_lastKbIntVal)
  ; switch(lastKeyboardIntVal)
  cp    0x80
  jr    nz,isrKbJoy2
  ld    b,a
  ld    (_joySt0),a   ; joySt0 = inkey
  jp    isrKbExit
isrKbJoy2:
  cp    0x81
  jr    nz,isrKbJoy3
  ld    b,a
  ld    (_joySt1),a   ; joySt1 = inkey
  jp    isrKbExit
isrKbJoy3:
  cp    0x82
  jr    nz,isrKbJoy4
  ld    b,a
  ld    (_joySt2),a   ; joySt2 = inkey
  jp    isrKbExit
isrKbJoy4:
  cp    0x83
  jr    nz,isrKbJoy5
  ld    b,a
  ld    (_joySt3),a   ; joySt3 = inkey
  jp    isrKbExit
isrKbJoy5:
  ; default (not joystick so just save inkey into the buffer at kbdBufWritePos0
  push  hl

  ld    a,(_kbdBufWritePos)
  ld    hl,_kbdBuffer
  ; add HL + A
  ld    a,l
  ld    l,a
  adc   a,h
  sub   l
  ld    h,l
  ; hl points at _kbdBuffer[_kbdBufWritePos]
  ld    a,b
  ld    (hl),a    ; save inkey into kbdBuffer

  ld    a,(_kbdBufWritePos)
  inc   a
  ld    (_kbdBufWritePos),a ; kbdBuWritePos ++

  pop   hl
isrKbExit:
  pop   bc
  pop   af
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
