; vim: set ft=z80 ts=2 sw=2 et:
stacktop equ 0xD400

  .code
  ld    hl, 0
  add   hl,sp
  ld    (oldstack),hl

  ld    sp,stacktop

  call  __init_sys
  call  _main

  pop   de

  ld    sp,(oldstack)
  ret

oldstack: .ds 2
