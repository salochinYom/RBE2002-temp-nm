#include <SharpIR.h>

SharpIR ir1;

SharpIR::SharpIR() {}

void SharpIR::init()
{
    //SPI to talk to the MCP3002
    SPI.begin(); //defaults to VPSI: SCK, MISO, MOSI, SS; see above
    pinMode(SS, OUTPUT); //need to set the CS to OUTPUT
}

uint16_t SharpIR::readMCP3002(bool force)
{
    uint16_t retVal = 0;
    if((millis() - lastADCread >= ADC_PERIOD) || force)
    {
        lastADCread = millis();

        // This will command the MCP to take a reading on CH0
        //0x7800 ch1 0x6800 ch0
        // Figure 6.1 of the datasheet shows the bit arrangement
        uint16_t cmdByte = 0x6800; 

        //start the SPI session
        SPISettings spiSettings; //defaults to (clk freq = 1000000, MSBFIRST, SPI_MODE0), which is what we want
        SPI.beginTransaction(spiSettings); 

        //open communication with the MCP3002
        digitalWrite(SS, LOW); 

        //this line both sends the command to read AND retrieves the result
        //the leading bits are indeterminate and need to be stripped off
        uint16_t ADCvalue = SPI.transfer16(cmdByte) & 0x03ff;

        //end communication
        digitalWrite(SS, HIGH); 

        //close the SPI session
        SPI.endTransaction(); 

        retVal = ADCvalue;
        state &= ~ADC_READ;
    }

    return retVal;
}

// TODO: get correct transfer function
bool SharpIR::getDistance(float& distance) {
    // old transfer function: 4396*1/d + 133
    // new transfer function: 6194*1/d + 87.4 (after removing 5cm data points)
    uint16_t adcReading = ir1.readMCP3002(false); //gets adc reading
    if(!(state & ADC_READ)){ 
        distance = 6194.0/(adcReading - 87.4);
        state |= ADC_READ; //sets value to we have read or true.
        return true;
    }
    return false;
}