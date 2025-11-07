; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_readstr
  .code
_cpm_readstr:
  push  bc
  ld    c,0xa
  ex    de,hl
  call  5
  pop   bc
  ret
