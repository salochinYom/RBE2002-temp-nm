/*
 * Code for interfacing with the MCP3002 ADC using the SPI bus on the ESP32.
 * This code is written to use specific pins:
 * 
 * MISO = 19
 * MOSI = 23
 * SCLK = 18
 * SS   = 5
 * 
 * RX   = 16 (inverted for MaxBotix!)
 * (best not to use TX-17 for anything else, since the uart will likely conflict with pin operation)
 * 
 * pulse width is read on: 35
 * ultrasonic control pin: 2
 */

#include <Arduino.h>
#include <SPI.h>
#include <SharpIR.h>
// #include <Timer.h>

// Timer printTimer(50);

void setup()
{
  delay(1000);
  Serial.begin(115200);
  Serial.println("Velkommen til"); //welcome in german
  ir1.init();
}

void loop() 
{
  // uint16_t ADCreading = ir1.readMCP3002();
  // if(ADCreading) 
  // {
  //   Serial.print(ADCreading);
  //   Serial.print(',');
  //   Serial.print(0); //TODO: change this line to output distance in cm
  //   Serial.println(',');
  // }
  float distance = 0;
  if (ir1.getDistance(distance)) {
    Serial.println(distance);
  }
}
