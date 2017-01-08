#include "Motor.class.h"

#define SERVOBLASTER_DEV_FILE			"/dev/servoblaster"

Motor::Motor(int servoNumber)
{
	this->servoNumber = servoNumber;
	this->start();
}

void Motor::start(void){
	this->fp = fopen(SERVOBLASTER_DEV_FILE, "w");
    if (this->fp == NULL) {
        throw new std::exception("Error opening file"); 
    } 
	
}

void Motor::setValue(int value){
	fprintf(this->fp,std::to_string(this->servoNumber)+"="+std::to_string(value)+"%");
}

void Motor::stop(void){
	fclose(this->fp);
    fflush(this->fp); 
}

Motor::~Motor(void)
{
    this->stop();
}