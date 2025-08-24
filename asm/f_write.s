  .export _f_write
  .code
_f_write:
  push  bc
  ld    c,0x15
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
