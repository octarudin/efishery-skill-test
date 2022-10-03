#ifndef Databases_h
#define Databases_h

#include <EEPROM.h>

/** 
 *  Saving 10-bytes of Data
 *  Serially / FIFO
 */

#define firstAddr 0x00
#define totalData 10    // in bytes
unsigned char currentAddress = firstAddr;

void saveDataInternally(unsigned char *data) {
  EEPROM.put(currentAddress, *data);
  // EEPROM.commit();
  currentAddress += sizeof(*data);     //update address  value
  if (currentAddress > totalData) {
    currentAddress = firstAddr;
  }
}
#endif
