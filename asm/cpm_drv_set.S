; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_drv_set
  .code
_cpm_drv_set:
  push  bc
  ld    e,l
  ld    c,0x0e
  call  5
  ld    h,0
  pop   bc
  ret
