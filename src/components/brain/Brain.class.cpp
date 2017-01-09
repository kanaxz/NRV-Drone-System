#include "Brain.class.h"

Brain::Brain()
{
	this->initMotors();
}

Brain::~Brain()
{
    this->motors.clear();
}

void Brain::initMotors(void){
	this->motors.registerMotor(new Motor(ServoNumbers::BL));
	this->motors.registerMotor(new Motor(ServoNumbers::BR));
	this->motors.registerMotor(new Motor(ServoNumbers::FL));
	this->motors.registerMotor(new Motor(ServoNumbers::FR));
}