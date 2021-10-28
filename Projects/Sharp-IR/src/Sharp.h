#include <Timer.h>
#include <SPI.h>
#include <Arduino.h>

class Sharp
{
private:
    long unsigned int lastADCread;
public:
    uint16_t readMCP3002(bool force);
    void init();//intialize the thing

};