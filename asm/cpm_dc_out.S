; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_dc_out
  .code
_cpm_dc_out:
  ld    c,6
  ex    de,hl
  jp    5

