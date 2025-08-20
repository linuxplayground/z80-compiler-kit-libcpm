  .export _writestr
  .code
_writestr:
  push  bc
  ld    c,9
  ex    de,hl
  call  5
  pop   bc
  ret
