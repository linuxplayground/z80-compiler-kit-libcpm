#ifdef NABU

#include "io.h"
#include "nabu_constants.h"

  .export _nabu_init
  .export _lastKeyoardIntVal
  .export _lastKeyboardIntVal
  .export _kbdBufferReadPos
  .export _kbdBufferWritePos
  .export _joyStatus
  .export _kbdBuffer

  .data

origint:                   .ds 1
_lastKeyboardIntVal:       .ds 1
_kbdBufferReadPos:         .ds 1
_kbdBufferWritePos:        .ds 1
_joyStatus:                .ds 2
_kbdBuffer:                .ds 0xff

tms_status_reg:            .ds 1
tms_is_ready:              .ds 1

  .code


_nabu_init:
  ;Turn off the rom
  ld    a,0x03 ;CONTROL_ROMSEL|CONTROL_VDOBUF
  out   (IO_CONTROL),a
  di    ; disable interrupts

  im    2

#if 0
  ld    hl, isrKeyboard
  ld    (0xff00+4), hl
#endif

  ld    hl, isrVdp
  ld    (0xff00+6), hl

  ld    b,0x07
  ld    c,01111111b
  call  _ay_write        ; configure PORTA for writing and port B for reading

  ld    a,IO_PORTA
  call  ay_read         ; get the current interrupt mask from AY Port A
  or    0x30; INT_MASK_KEYBOARD|INT_MASK_VDP
  ld    c,a
  ld    b,IO_PORTA
  call  _ay_write
  ei    ; enable interrupts
  ret

isrKeyboard:
  push  bc
  push  de
  push  hl
  push  af
  push  iy
  push  ix

  ld  hl,(__tmp)
  push  hl
  ld  hl,(__hireg)
  push  hl
  ld  hl,(__tmp2)
  push  hl
  ld  hl,(__tmp2+2)
  push  hl
  ld  hl,(__tmp3)
  push  hl
  ld  hl,(__tmp3+2)
  push  hl

  call _isrKeybaord

  pop hl
  ld  hl,(__tmp3+2)
  pop hl
  ld  hl,(__tmp3)
  pop hl
  ld  hl,(__tmp2+2)
  pop hl
  ld  hl,(__tmp2)
  pop hl
  ld  hl,(__hireg)
  pop hl
  ld  hl,(__tmp)

isrKeyboard_exit:
  pop   ix
  pop   iy
  pop   af
  pop   hl
  pop   de
  pop   bc
  ei
  reti
#endif
