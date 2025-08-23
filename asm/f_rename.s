  .export _f_rename
  .code
_f_rename:
  push  bc
  ld    c,0x17
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
