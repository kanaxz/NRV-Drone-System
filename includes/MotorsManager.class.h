
#ifndef _MOTORS_MANAGER_H_
#define _MOTORS_MANAGER_H_

#include "Motor.class.h"
#include <list>
class 
{

private:
	std::list<Motor*> motors;
public:
    MotorsManager();
    ~MotorsManager();



    void registerMotor(Motor *newMotor);
    void setMotorValue(int servoNumber,int value);
    Motor* getMotorByServoNumber(int servoNumber);
    void clear(void);

};

#endif /* _MOTORS_MANAGER_H_ */
