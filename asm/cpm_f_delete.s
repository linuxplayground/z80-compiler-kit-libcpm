  .export _cpm_f_delete
  .code
_cpm_f_delete:
  push  bc
  ld    c,0x13
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
