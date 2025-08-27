; vim: set ft=z80:
stacktop equ 0xD400

  .code
  ld  hl, 0
  add hl,sp
  ld  (oldstack),hl

  ld  sp,stacktop
  call _main

  pop  de

  ld sp,(oldstack)
  ret

oldstack: .ds 2
