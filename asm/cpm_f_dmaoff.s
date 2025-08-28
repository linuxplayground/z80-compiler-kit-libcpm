  .export _cpm_f_dmaoff
  .code
_cpm_f_dmaoff:
  push  bc
  ld    c,0x1A
  ex    de,hl
  call  5
  pop   bc
  ret

