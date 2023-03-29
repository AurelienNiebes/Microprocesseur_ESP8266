/*
  This is a simple sketch to test BH1750FVI Light Sensor
  which communicates using the I2C Protocol 
  
  It writes out the lux value over the serial port
  Connect this sensor as follows:
  VCC >>> 3.3V or 5V
  SDA >>> A4 
  SCL >>> A5
  addr >> Gnd or VCC
  Gnd >>> Gnd
  
  BH1750FVI Sensor Setup 
  
  ##### I2C Addresses #####
  Addr_LOW 0x23 // Device address when address pin LOW
  Addr_HIGH 0x5C // Device address when address pin High
   
  ##### Modes ##### 
  Continuous_H - 1 lx resolution (16 bit), 120ms sampling time
  Continuous_H2 -  0.5 lx resolution (18 bit), 120ms sampling time
  Continuous_L - 4 lx resolution (15 bit), 16ms sampling time
  OneTime_H
  OneTime_H2
  OneTime_L
  
  Default for Begin() is Addr_LOW and Continuous_H
  
 */
 
// The library includes
#include <Wire.h>
#include "BH1750FVI.h"

// Pin that LED is connected to
// Connect LED With 100ohm resistor
#define LEDPin LED_BUILTIN

// Initialize the BH1750FVI class
BH1750FVI LightSensor;



void setup() {   
  // put your setup code here, to run once:
  
  // Start Serial communication
   Serial.begin(115200);
 
  // Start the light sensor by turning on and initializing it.
  LightSensor.Begin(Addr_LOW, Continuous_H);
 
  // Sets the measurement time register
  // This allows for adjusting the sensitivity
  // It also allows for extension of the sensor's range.
  //LightSensor.SetMTReg(69);
  
  
  // Scales the sensitivity of the sensor by changing measurement time w/o re-scaling
  // Increasing the sensitivity accounts for something covering sensor (window)
  // Decreasing the sensitivity accounts 
  // The range in sensitivity scaling is 0.45 to 3.68.  Default is 1.00
  //LightSensor.SetSensitivity(1.00);

}


void loop() {
  // put your main code here, to run repeatedly:
  
  // Get the value in lux.  It returns a float that's significant to 1 or 2 digits
  float lux = 0;// Get Lux value
  lux=LightSensor.GetLux();
  // Print out the lux value
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.println(" lux");
  
  // Measure every second
  delay(1000);
}