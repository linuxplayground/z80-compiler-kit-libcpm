  .export _f_sfirst
  .code
_f_sfirst:
  push  bc
  ld    c,0x11
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
