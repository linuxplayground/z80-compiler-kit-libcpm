  .export _f_make
  .code
_f_make:
  push  bc
  ld    c,0x16
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
