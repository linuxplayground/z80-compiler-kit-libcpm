  .export _f_delete
  .code
_f_delete:
  push  bc
  ld    c,0x13
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
