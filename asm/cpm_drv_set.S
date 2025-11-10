; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_drv_set
  .code
;extern uint_fast8_t cpm_drv_set(uint_fast8_t drive);
_cpm_drv_set:
  ld    hl,2
  add   hl,sp
  ld    e,(hl)  ; drive
  push  bc
  ld    c,0x0e
  call  5
  ld    h,0
  pop   bc
  ret
