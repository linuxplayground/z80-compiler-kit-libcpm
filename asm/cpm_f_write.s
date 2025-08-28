  .export _cpm_f_write
  .code
_cpm_f_write:
  push  bc
  ld    c,0x15
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
