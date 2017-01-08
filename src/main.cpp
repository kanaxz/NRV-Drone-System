
#include "Brain.class.h"
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

  
  motorFL = new Motor(17); // Instanciates the motor from GPIO 17
  motorFR = new Motor(17); // Instanciates the motor from GPIO 17
  motorBL = new Motor(17); // Instanciates the motor from GPIO 17
  motorBR = new Motor(17); // Instanciates the motor from GPIO 17

  // Open the device in non-blocking mode
  

    FILE *fp;
    fp = fopen("/dev/servoblaster", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(0); 
    }   
    
    fprintf(fp, "1=20%");
   
  /*
  while(true){
    char message[10];
    std::cin>>message;
    
    std::cout<< "message="<<message<<",size="<<strlen(message)<<std::endl;
    message[strlen(message)] = '\0';
    fprintf(fp, message);
    
  }
  // Try to write some data
  
  /**/
 
  
   fclose(fp);
    fflush(fp); 

  // DESTROY TIME
  delete motorFL;
  delete motorFR;
  delete motorBL;
  delete motorBR;

  return (0);
}
