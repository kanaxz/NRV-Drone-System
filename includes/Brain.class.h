
#ifndef _BRAIN_H_
#define _BRAIN_H_

#include "MPU6050.class.h"
#include "Motor.class.h"
#include "PID.class.h"

class Brain
{

private:
	// Front left motor 
  	Motor			*motorFL;
  	// Front right motor 
  	Motor			*motorFR;
  	// Back left motor 
  	Motor			*motorBL;
  	// Back right motor 
  	Motor			*motorBR;

    MPU6050   *IMU;

    //pitch
    PID  pitchPID,rollPID;
public:
    Brain();
    ~Brain();



    void initMotors(void);

};

#endif /* _BRAIN_H_ */
