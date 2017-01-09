#include "MotorsManager.class.h"


MotorsManager::MotorsManager(void)
{
	
}

MotorsManager::~MotorsManager(void)
{

}

void MotorsManager::registerMotor(Motor *newMotor){
	Motor *existingMotor = this->getMotorByServoNumber(newMotor->getServoNumber());
	if(existingMotor == null){
		this->motors.push_back(newMotor);
	}
	else{
		//todo : motor with the same number already exists, throw exception
	}
}

void MotorsManager::setMotorValue(int servoNumber,int value){
	Motor *targetMotor = this->getMotorByServoNumber(servoNumber);
	if(targetMotor != NULL){
		targetMotor->setValue(value);
	}
	else{
		//TODO : exception
	}
}

void MotorsManager::getMotorByServoNumber(int servoNumber){

	for (std::list<int>::iterator it = this->motors.begin(); it != this->motors.end(); it++)
    {
    	Motor *iMotor = (*it);
    	if(iMotor->getServoNumber() == servoNumber){
    		return iMotor;
    	}
    }
    return NULL;
}

void MotorsManager::clear(void){
	while(!this->motors.empty()){
		delete[] this->motors.front();
		this->motors.pop_front();
	} 
}