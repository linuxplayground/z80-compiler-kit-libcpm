  .export _cpm_f_readrand
  .code
_cpm_f_readrand:
  push  bc
  ld    c,0x21
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
