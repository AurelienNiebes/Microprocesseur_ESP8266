// Wire Controller Reader
// by Nicholas Zambetti <http://www.zambetti.com>
// Demonstrates use of the Wire library
// Reads data from an I2C/TWI peripheral device
// Refer to the "Wire Peripheral Sender" example for use with this
// Created 29 March 2006
// This example code is in the public domain.
#include <Wire.h>
int Adresse=0x46>>1;//0x46;
void setup() {
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(115200);  // start serial for output
}

int reading=0;
void loop() {
  //Pour envoyer des infos
  Wire.beginTransmission(Adresse); // transmit to device #112 (0x70)
  // the address specified in the datasheet is 224 (0xE0)
  // but i2c addressing uses the high 7 bits so it's 112
  Wire.write(byte(0x20));      // sets register pointer to the command register (0x00)
  // use 0x51 for centimeters
  // use 0x52 for ping microseconds
  Wire.endTransmission();      // stop transmittin*/
  //delay(120);
  Wire.requestFrom(Adresse, 2);    // request 2 bytes from peripheral device #8 nous, 0X46
  if (2 <= Wire.available()) { // if two bytes were received
    reading = Wire.read();  // receive high byte (overwrites previous reading)
    reading = reading << 8;    // shift high byte to be high 8 bits
    reading |= Wire.read(); // receive low byte as lower 8 bits
    Serial.println(reading);   // print the reading
  }
  delay(500);

}