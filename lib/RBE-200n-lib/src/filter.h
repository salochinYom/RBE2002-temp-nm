#include <Arduino.h> 

class filter
{
private:
    const int listleng = 4; //list length - 1
    const int middleOfList = 2; //middle value in list for sort function
    int listpos = 0;
    float running[5]; //list that is directly read from
    float mathop[5]; //list that is sorted for math.
    float cleanList[5]; //list used to reset other lists

    void transferlist(); //sets mathop to running list values
    void sortMathop(); //sorts operational list

public:
    void addSample(float sample); //adds sample to running list
    float getMedian(); //gets median of samples
    float getAvg(); //gets 5 val running average
};


