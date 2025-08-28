  .export _cpm_constat
  .code
_cpm_constat:
  push  bc
  ld    c,0xb
  call  5
  pop   bc
  ret
