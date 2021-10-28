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
#include <Rangefinder.h>

//#include <MaxBotix.h>

Rangefinder ultrasonic;

void setup()
{
  delay(1000);
  ultrasonic.attach(SIDE_ULTRASONIC_TRIG, SIDE_ULTRASONIC_ECHO);
  Serial.begin(115200);
  Serial.println("Velkommen til"); //welcome in german

}

void loop() 
{
  if(ultrasonic.newReading) 
  {
    int time = ultrasonic.getRoundTripTimeMicroSeconds();
    Serial.print(time);
    Serial.print(',');
    Serial.print((time - 429)/46.9); //TODO: change this line to output distance in cm
    Serial.println(',');
  }
}
