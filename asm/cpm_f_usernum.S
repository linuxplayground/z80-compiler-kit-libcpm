; vim: set ft=z80 ts=2 sw=2 et:
;****************************************************************************
;    Wrapper functions for CPM are all public domain.
;    See: https://www.seasip.info/Cpm/bdosfunc.html
;****************************************************************************

  .export _cpm_f_usernum
  .code
;extern uint_fast8_t cpm_f_usernum(uint_fast8_t num);
_cpm_f_usernum:
  ld    hl,2
  add   hl,sp
  ld    e,(hl)  ; num

  push  bc
  ld    c,0x20
  call  5
  ld    l,a
  ld    h,0
  pop   bc
  ret
