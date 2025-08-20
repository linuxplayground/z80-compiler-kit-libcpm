  .export _constat
  .code
_constat:
  push  bc
  ld    c,0xb
  call  5
  pop   bc
  ret
