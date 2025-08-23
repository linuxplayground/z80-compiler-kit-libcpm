  .export _f_read
  .code
_f_read:
  push  bc
  ld    c,0x14
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret

