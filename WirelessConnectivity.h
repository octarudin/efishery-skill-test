#ifndef WirelessConnectivity_h
#define WirelessConnectivity_h

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(2, 4); // CE, CSN
const byte address[6] = "00001";

#endif
