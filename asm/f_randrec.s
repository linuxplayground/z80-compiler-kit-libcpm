  .export _f_randrec
  .code
_f_randrec:
  push  bc
  ld    c,0x25
  ex    de,hl
  call  5
  pop   bc
  ret
