  .export _cpm_f_rename
  .code
_cpm_f_rename:
  push  bc
  ld    c,0x17
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
