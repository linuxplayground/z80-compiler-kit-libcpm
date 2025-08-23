  .export _f_dmaoff
  .code
_f_dmaoff:
  push  bc
  ld    c,0x1A
  ex    de,hl
  call  5
  pop   bc
  ret

