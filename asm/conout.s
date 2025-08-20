  .export _conout
  .code
_conout:
  push  bc
  ld    c,2
  ex    de,hl
  call  5
  pop   bc
  ret

