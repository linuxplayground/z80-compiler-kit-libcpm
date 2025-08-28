  .export _cpm_conin
  .code
_cpm_conin:
  push  bc
  ld    c,1
  call  5
  pop   bc
  ret

