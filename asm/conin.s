  .export _conin
  .code
_conin:
  push  bc
  ld    c,1
  call  5
  pop   bc
  ret

