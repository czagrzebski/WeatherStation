
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  radio.begin();
  Serial.println("Starting!");
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    uint8_t data[3]; //Byte array of Sensor Data (Temperature, Humidity, Pressure)
    radio.read(&data, sizeof(data));
    Serial.println(data[2]);
  }
}
