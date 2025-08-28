  .export _cpm_drv_allreset
  .code
_cpm_drv_allreset:
  push  bc
  ld    c,0x0d
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
