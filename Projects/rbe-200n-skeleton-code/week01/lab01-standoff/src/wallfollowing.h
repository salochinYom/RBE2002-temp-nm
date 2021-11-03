#include <PIDcontroller.h>

class wallFollowingController
{
public:
    float leftSpeed = 0;
    float rightSpeed = 0;
    float targetDistance = 20;
    
private:
    float pi = 3.14;
    double WheeldiameterCM = 6.9; //nice


protected:
    float speed = 25;

    PIDController pidwallFollowing;
    public:
    wallFollowingController(void) : pidwallFollowing(0.005,0,0.00025,0.25) {} //TODO: edit gains 0.005, 0.0005, 0.00025, 0.25

    void processDistanceReading(float distance);
    void handleKeyPress(int16_t key);
};
