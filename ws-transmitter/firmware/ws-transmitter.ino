/*
* WeatherStation Transmitter Unit
* Version: v1.0
* Author: Creed Zagrzebski
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE (Pin 7), CSN (Pin 8)
boolean debug = false; //Debug Mode Flag
const byte address[6] = "00001";

byte temp = 1;
byte humidity = 10;
byte pressure = 12;

uint8_t data[3];

void setup() {
  Serial.begin(9600); //9600 baudrate for serial connection
  Serial.println("WeatherStation v1.0");
  
  //Start nRF24L01 Radio
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening(); //Send Only (Do not recieve)

  //Test Values
  data[0] = temp;
  data[1] = humidity;
  data[2] = pressure;

}

void loop() {
  //TODO: Fetch sensor data from Temperature Sensor

  const char text[] = "Hello World";
  Serial.println("Sending Request");
  
  //Write the data to be sent to the NRF24l01
  radio.write(&data, sizeof(data));
  delay(1000);
}