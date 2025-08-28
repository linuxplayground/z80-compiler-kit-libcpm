  .export _cpm_readstr
  .code
_cpm_readstr:
  push  bc
  ld    c,0xa
  ex    de,hl
  call  5
  pop   bc
  ret
