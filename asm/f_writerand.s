  .export _f_writerand
  .code
_f_writerand:
  push  bc
  ld    c,0x22
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
