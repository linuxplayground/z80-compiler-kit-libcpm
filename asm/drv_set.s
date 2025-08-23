  .export _drv_set
  .code
_drv_set:
  push  bc
  ld    e,l
  ld    c,0x0e
  call  5
  ld    h,0
  pop   bc
  ret
