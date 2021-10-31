#include <PIDcontroller.h>

class wallFollowingController
{
public:
    float leftSpeed = 0;
    float rightSpeed = 0;

protected:
    float targetDistance = 10;
    float speed = 25;

    PIDController pidwallFollowing;
    public:
    wallFollowingController(void) : pidwallFollowing(1, 0, 0) {} //TODO: edit gains

    void processDistanceReading(float distance);
    void handleKeyPress(int16_t key);
};
