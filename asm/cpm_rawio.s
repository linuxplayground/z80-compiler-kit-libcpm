; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_rawio
  .code
_cpm_rawio:
  ld    c,0x6
  call  5
  ld    l,a
  ld    h,0
  ret
