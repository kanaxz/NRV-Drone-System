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
    	//TODO : exception
    	std::cout<<"Error opening file"<<std::endl;
        //throw new std::exception("Error opening file"); 
    } 
	
}

void Motor::setValue(int value){
	std::string message = std::to_string(this->servoNumber)+"="+std::to_string(value)+"%";
	fprintf(this->fp,message);
}

void Motor::stop(void){
	fclose(this->fp);
    fflush(this->fp); 
}

Motor::~Motor(void)
{
    this->stop();
}