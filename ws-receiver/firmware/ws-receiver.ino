/*
* WeatherStation Receiver Unit
* Version: v1.0
* Author: Creed Zagrzebski
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00004";
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  radio.begin();
  Serial.println("WeatherStation Receiver");
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    Serial.println("Data Received from station");
    uint8_t data[3]; //Byte array of Sensor Data (Temperature, Humidity, Pressure)
    radio.read(&data, sizeof(data));
    Serial.println(data[2]);
  }
}
