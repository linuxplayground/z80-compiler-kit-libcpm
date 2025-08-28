  .export _cpm_drv_reset
  .code
_cpm_drv_reset:
  push  bc
  ld    c,0x25
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
