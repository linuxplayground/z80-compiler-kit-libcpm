  .export _cpm_f_snext
  .code
_cpm_f_snext:
  push  bc
  ld    c,0x12
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
