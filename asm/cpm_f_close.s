  .export _cpm_f_close
  .code
_cpm_f_close:
  push  bc
  ld    c,0x10
  ex    de,hl
  call  5
  pop   bc
  ret
