/*
* NRF24l01 Transmitter Unit Program
*
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE (Pin 7), CSN (Pin 8)
const byte address[6] = "00001"; //radio address

void setup() {
  Serial.begin(9600); //9600 baudrate for serial connection
  Serial.println("WeatherStation v1.0");
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
}

void loop() {
  //TODO: Fetch sensor data from BME280

  const char text[] = "Hello World";
  Serial.println("Sending Request");
  
  //Write the data to be sent to the NRF24l01
  radio.write(&text, sizeof(text));
  delay(1000);
}
