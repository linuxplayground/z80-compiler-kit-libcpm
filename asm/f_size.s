  .export _f_size
  .code
_f_size:
  push  bc
  ld    c,23
  ex    de,hl
  call  5
  pop   bc
  ret
