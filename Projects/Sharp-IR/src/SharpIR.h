#ifndef __SHARPIR_H
#define __SHARPIR_H

#include <Timer.h>
#include <SPI.h>
#include <Arduino.h>

#define ADC_READ    0x08
#define ADC_PERIOD 50 //ms

class SharpIR
{
private:
    uint8_t state = 0;
    uint32_t lastADCread = 0;

public:
    SharpIR(void);  
    void init(void);

    //Reads the MCP3002 ADC; returns ADC result
    uint16_t readMCP3002(bool force = false);

    /**
     * TODO: Write a getDistance() function for the distance method of your choice.
     * 
     * See the .cpp file.
     */
    bool getDistance(float& distance);

};

extern SharpIR ir1;

#endif