  .export _cpm_f_open
  .code
_cpm_f_open:
  push  bc
  ld    c,0x0f
  ex    de,hl
  call  5
  pop   bc
  ret

