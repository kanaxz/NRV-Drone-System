#include "Motor.class.h"

#define SERVOBLASTER_DEV_FILE			"/dev/servoblaster"

Motor::Motor(int servoNumber)
{
	this->servoNumber = servoNumber;
}

void Motor::start(void){

}

Motor::~Motor(void)
{
    
}