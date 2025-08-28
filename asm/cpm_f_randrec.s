  .export _cpm_f_randrec
  .code
_cpm_f_randrec:
  push  bc
  ld    c,0x25
  ex    de,hl
  call  5
  pop   bc
  ret
