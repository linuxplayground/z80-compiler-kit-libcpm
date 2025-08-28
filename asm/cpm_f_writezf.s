  .export _cpm_f_writezf
  .code
_cpm_f_writezf:
  push bc
  ld    c,0x28
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
