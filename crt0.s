  .export __STACK
  .code
  ld  (__STACK), sp
  call _main
  pop  de
  jp 0

__STACK: .ds 2
