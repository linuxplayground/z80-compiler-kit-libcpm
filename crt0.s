  .export __STACK

stacktop equ 0xD400

  .code
  ld  hl, 0
  add hl,sp
  ld  (__STACK),hl

  ld  sp,stacktop
  call _main

  pop  de

  ld sp,(__STACK)
  ret

__STACK: .ds 2
