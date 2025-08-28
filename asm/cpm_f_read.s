  .export _cpm_f_read
  .code
_cpm_f_read:
  push  bc
  ld    c,0x14
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret

