#include <wallfollowing.h>
#include "ir_codes.h"

void wallFollowingController::processDistanceReading(float distance)
{
    float error = targetDistance - distance;
    float effort = pidwallFollowing.CalcEffort(error);

    leftSpeed = speed * (1 - effort);
    rightSpeed = speed * (1 + effort);

    Serial.print(targetDistance);
    Serial.print('\t');
    Serial.print(distance);
    Serial.print('\t');
    Serial.print(error);
    Serial.print('\t');
    Serial.print(effort);
    Serial.print('\t');
    Serial.print(leftSpeed);
    Serial.print('\t');
    Serial.print(rightSpeed);
    Serial.print('\t');
}

void wallFollowingController::handleKeyPress(int16_t key)
{
    switch(key)
    {
        case CHplus:
            speed += 5;
            break;

        case CHminus:
            speed -= 5;
            break;

        case NUM_0:
            targetDistance = 0;
            break;
        case NUM_1:
            targetDistance = 10;
            break;
        case NUM_2:
            targetDistance = 20;
            break;
        case NUM_3:
            targetDistance = 30;
            break;
        case NUM_4:
            targetDistance = 40;
            break;
        case NUM_5:
            targetDistance = 50;
            break;
        case NUM_6:
            targetDistance = 60;
            break;
        case NUM_7:
            targetDistance = 70;
            break;
        case NUM_8:
            targetDistance = 80;
            break;
        case NUM_9:
            targetDistance = 90;
            break;

        default:
            // if(key >= NUM_0 && key <= NUM_9)
            // {
            //     //TODO: implement standoff distance
            //     targetDistance = (key - 16) * 10;
            // }
            break;
    }
}