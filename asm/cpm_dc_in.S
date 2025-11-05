; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_dc_in
  .code
_cpm_dc_in:
  ld    c,6
  ld    e,0xFF
  call  5
  ld    l,a
  ld    h,0
  ret

