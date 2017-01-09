#include "Brain.class.h"

Brain::Brain()
{
	this->initMotors();
}

Brain::~Brain()
{
	
}

void Brain::initMotors(void){
	this->motorBL = new Motor(ServoNumbers::BL);
	this->motorBR = new Motor(ServoNumbers::BR);
	this->motorFL = new Motor(ServoNumbers::FL);
	this->motorFR = new Motor(ServoNumbers::FR);
}