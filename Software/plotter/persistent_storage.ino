#include <EEPROM.h>

void eepromWriteLong(int addr, long data) {
  for(int b=0 ; b<4 ; b++) {
    EEPROM.write(addr+b, data & 0xff);
    data = data >> 8;
  }
}

long eepromReadLong(int addr) {
  long ret = 0;
  for(int b=0 ; b<4 ; b++) {
    ret = (ret<<8) | EEPROM.read(addr+(3-b));
  }
  return ret;
}