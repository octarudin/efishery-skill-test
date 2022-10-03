/**
 * Files:
 * > Forwarder Node as Main File
 * --> AsyncWebServer as Node Interface
 * --> WirelessConnectivity as Receiver Data from Sensor Node
 * --> MQTT as Connector between forwarder node and User Interface
 */
#include "NodeMCUGPIO.h"
#include "CommonVariables.h"
#include "Databases.h"
#include "WiFiSettings.h"
#include "AsyncWebServer.h"
#include "WirelessConnectivity.h"
#include "MQTTSettings.h"

void setup() {
  Serial.begin(9600);
  EEPROM.begin(totalData);
  
  radio.begin();                       //nRF24L01 error
  radio.openReadingPipe(0, address);   //Setting the address at which we will receive the data
  radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
  radio.startListening();              //This sets the module as receiver

  // Connect to Wi-Fi, 2022-10-01 Change to setup_wifi()
  setup_wifi();
  
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  
//  // Route for root / web page
//  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
//    request->send_P(200, "text/html", index_html, processor);
//  });

//  // Send a GET request to <ESP_IP>/update?msg=<inputMessage1>
//  server.on("/update", HTTP_GET, [] (AsyncWebServerRequest *request) {
//    String inputMessage1;
//    
//    // GET input1 value on <ESP_IP>/update?msg=<inputMessage1>
//    // 2022-10-02 PARAM_INPUT_2 was removed
//    if (request->hasParam(PARAM_INPUT_1)) {
//      inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
//      client.publish("pub_octa", inputMessage1.c_str());
//    }
//    else {
//      inputMessage1 = "No message sent";
//    }
//    // 2022-10-02 Serial prints were removed
//    request->send(200, "text/plain", "OK");
//  });

//  // Start server
//  server.begin();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  if (radio.available()) {
    unsigned char data;                 //Saving the incoming data
    radio.read(&data, sizeof(data));    //Reading the data
    saveDataInternally(&data);
    Serial.print("Data Diterima: ");
    Serial.println(data);
    String payload = String(data);
    client.publish("pub_octa", payload.c_str());
  }
}
