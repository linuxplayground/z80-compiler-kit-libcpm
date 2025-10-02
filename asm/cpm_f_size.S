; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_f_size
  .code
_cpm_f_size:
  ld    c,0x23
  ex    de,hl
  call  5
  ret
