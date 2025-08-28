  .export _cpm_conout
  .code
_cpm_conout:
  push  bc
  ld    c,2
  ex    de,hl
  call  5
  pop   bc
  ret

