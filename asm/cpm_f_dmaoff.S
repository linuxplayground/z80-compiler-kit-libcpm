; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_f_dmaoff
  .code
;extern void cpm_f_dmaoff(char *dma);
_cpm_f_dmaoff:
  pop   hl  ; return
  pop   de  ; *dma
  push  de
  push  hl
  push  bc
  ld    c,0x1A
  call  5
  pop   bc
  ret

