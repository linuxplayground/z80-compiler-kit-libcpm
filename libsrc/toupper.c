char toupper(char c) {
  if ( (c >= 'a') && (c <= 'z') ) {
    c &= 0xDF;
  }
  return c;
}

