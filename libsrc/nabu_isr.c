#ifdef NABU
#include <stdint.h>
#include <io.h>

extern uint8_t _builtin_in(uint8_t port);

extern uint8_t inKey;
extern uint8_t lastKeyboardIntVal;
extern uint8_t joyStatus[4];
extern uint8_t kbdBuffer[256];
extern uint8_t kbdBufferWritePos;

void isrKeyboard() {
      uint8_t inKey = _builtin_in(IO_KEYBOARD);

    if (inKey >= 0x80 && inKey <= 0x83) {

      lastKeyboardIntVal = inKey;
    } else if (inKey < 0x90 || inKey > 0x95) {

      switch (lastKeyboardIntVal) {
        case 0x80:
          lastKeyboardIntVal = 0;
          joyStatus[0] = inKey;
          break;
        case 0x81:
          lastKeyboardIntVal = 0;
          joyStatus[1] = inKey;
          break;
        case 0x82:
          lastKeyboardIntVal = 0;
          joyStatus[2] = inKey;
          break;
        case 0x83:
          lastKeyboardIntVal = 0;
          joyStatus[3] = inKey;
          break;
        default: {

          kbdBuffer[kbdBufferWritePos] = inKey;

          kbdBufferWritePos++;
        }
      }
    }
}
#endif
