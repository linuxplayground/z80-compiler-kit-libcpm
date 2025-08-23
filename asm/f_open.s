  .export _f_open
  .code
_f_open:
  push  bc
  ld    c,0x0f
  ex    de,hl
  call  5
  pop   bc
  ret

