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
#include <Sharp.h>
#include <Timer.h>

Sharp IR;

Timer printTimer(50);

//#include <MaxBotix.h>


void setup()
{
  delay(1000);
  Serial.begin(115200);
  Serial.println("Velkommen til"); //welcome in german
  IR.init();

}

void loop() 
{
  if(printTimer.isExpired()) 
  {
    uint16_t ADCreading = IR.readMCP3002(true);
    Serial.print(ADCreading);
    Serial.print(',');
    Serial.print(0); //TODO: change this line to output distance in cm
    Serial.println(',');
  }
}
