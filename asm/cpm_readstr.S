; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_readstr
  .code
;extern void cpm_readstr(char *buf);
_cpm_readstr:
  pop   hl  ; ret
  pop   de  ; *buf
  push  de
  push  hl
  push  bc
  ld    c,0xa
  call  5
  pop   bc
  ret
