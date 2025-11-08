; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_writestr
  .code
;extern void cpm_writestr(char *s);
_cpm_writestr:
  pop   hl  ; ret
  pop   de  ; *s
  push  de
  push  hl
  push  bc
  ld    c,9
  call  5
  pop   bc
  ret
