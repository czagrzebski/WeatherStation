/*
* WeatherStation Transmitter Unit
* Version: v1.0
* Author: Creed Zagrzebski
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


const byte address[6] = "00004";
uint8_t station_id = 1;
boolean debug = false; //Debug Mode Flag

RF24 radio(7, 8); // CE (Pin 7), CSN (Pin 8)

int temp;
int humidity;
int pressure;

//Station ID, Temperature, Humidity, Pressure
uint8_t data[4]; 

void setup() {
  Serial.begin(9600); //9600 baudrate for serial connection
  Serial.println("WeatherStation v1.0");
  
  //Start nRF24L01 Radio
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening(); //Send Only (Do not recieve)
}

void loop() {

  //Test Values
  temp = 1;
  humidity = 10;
  pressure = 12;

  data[0] = station_id;
  data[1] = temp;
  data[2] = humidity;
  data[3] = pressure;

  //Write the data to be sent to the NRF24l01
  Serial.println("Transmitting...");
  radio.write(&data, sizeof(data));
  delay(2000);
}