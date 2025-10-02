; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_drv_reset
  .code
_cpm_drv_reset:
  ld    c,0x25
  ex    de,hl
  call  5
  ld    l,a
  ld    h,0
  ret
