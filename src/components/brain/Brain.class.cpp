#include "Brain.class.h"

Brain::Brain():
	base pitchPID(2,0,0),
	base rollPID(2,0,0)
{
	this->imu = new MPU6050();
	this->initMotors();
}

Brain::~Brain()
{
	delete[] this->imu;
	this->destroyMotors();
}

void Brain::initMotors(void){
	this->motorBL = new Motor(ServoNumbers::BL);
	this->motorBR = new Motor(ServoNumbers::BR);
	this->motorFL = new Motor(ServoNumbers::FL);
	this->motorFR = new Motor(ServoNumbers::FR);
}

void Brain::destroyMotors(void){
	delete[] this->motorBL;
	delete[] this->motorBR;
	delete[] this->motorFL;
	delete[] this->motorFR;
}

void start(void){
	this->imu->bypassDrift();
	float ypr[3];
	float pitchTarget = 0,rollTarget =0;
	while(true){
		 if(this->imu->getFIFOCount() > 42) {
            this->imu->getYawPitchRoll(ypr);
            float 	pitchComputed = this->pitchPID.compute(ypr[1], pitchTarget), 
            		rollComputed = this->rollPID.compute(ypr[2], rollTarget);

	}
}