#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";     //Byte of array representing the address. This is the address where we will send the data. This should be same on the receiving side.
const long interval = 1000;            // interval at which to get data (milliseconds)
unsigned long previousMillis = 0;     // will store last time sensor was updated
unsigned char randomNumber;

void setup() {
  Serial.begin(9600);
  radio.begin();                  //Starting the Wireless communication
  radio.openWritingPipe(address); //Setting the address where we will send the data
  radio.setPALevel(RF24_PA_MIN);  //You can set it as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.stopListening();          //This sets the module as transmitter
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    randomNumber=random(255);
    Serial.print("Data Dikirim: ");
    Serial.println(randomNumber);
    radio.write(&randomNumber, sizeof(randomNumber));  //Sending the message to receiver 
  }
}
