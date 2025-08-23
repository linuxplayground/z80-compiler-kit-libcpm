  .export _drv_get
  .code
_drv_get:
  push  bc
  ld    c,0x19
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
