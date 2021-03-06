#include <Arduino.h> 
#include <filter.h>

void filter::transferlist(){
    for (int i = 0; i <= listleng; i++) //sum the list
    {
        mathop[i] = running[i];
    }

}

void filter::sortMathop(){
    int loc = 0; //keeps of pos in list
    while(loc < listleng)//while sorting
    {
        if(mathop[loc] <= mathop[loc + 1]) //if current is less than next
        {
            ++loc;
        }
        else
        {
            float lowerVal = mathop[loc + 1]; //store values to switch
            mathop[loc + 1] = mathop[loc];
            mathop[loc] = lowerVal; //write values
            loc -= 1; //increment down
            if(loc <= -1)
            {
                loc = 0; //floor 0
            }
        }
    }
}


void filter::addSample(float sample){
    running[listpos] = sample; //replaces value at location
    listpos++;
    if(listpos > listleng) //if pos overflows reset to zero
    {
        listpos = 0;
    }
}

float filter::getMedian(){
    transferlist(); //move running into mathop
    sortMathop(); //sorts list into values from lowest to highest
    return mathop[middleOfList]; //returns middle value of list
}

float filter::getAvg(){
    transferlist(); //move running into mathop
    float sum = 0; //sum number
    for (int i = 0; i <= listleng; i++) //sum the list
    {
        sum += mathop[i];
    }
    return sum/(listleng + 1); //returns avg    
}