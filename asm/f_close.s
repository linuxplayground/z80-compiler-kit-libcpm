  .export _f_close
  .code
_f_close:
  push  bc
  ld    c,0x10
  ex    de,hl
  call  5
  pop   bc
  ret
