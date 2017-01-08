
#include "Motor.class.h"
#include "unistd.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
  // Front left motor 
  Motor			*motorFL;
  // Front right motor 
  Motor			*motorFR;
  // Back left motor 
  Motor			*motorBL;
  // Back right motor 
  Motor			*motorBR;
  // Last key hit

  
  motorFL = new Motor(1); // Instanciates the motor from GPIO 17
  motorFR = new Motor(17); // Instanciates the motor from GPIO 17
  motorBL = new Motor(17); // Instanciates the motor from GPIO 17
  motorBR = new Motor(17); // Instanciates the motor from GPIO 17

  // Open the device in non-blocking mode
  

  motorFL->setValue(20);
 
  
 

  // DESTROY TIME
  delete motorFL;
  delete motorFR;
  delete motorBL;
  delete motorBR;

  return (0);
}
