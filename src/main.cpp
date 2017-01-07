
#include "Brain.class.h"
#include "unistd.h"
#include <iostream>

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
  int			key;
  // Servo mastah file descriptor
  std::filebuf		*fb;
  // Output stream servomaster
  std::istream		*is;
  
  motorFL = new Motor(17); // Instanciates the motor from GPIO 17
  motorFR = new Motor(17); // Instanciates the motor from GPIO 17
  motorBL = new Motor(17); // Instanciates the motor from GPIO 17
  motorBR = new Motor(17); // Instanciates the motor from GPIO 17
  // Open the file
  fb.open("/dev/servomaster", std::ios::in);
  // Output stream instanciation
  is = new istream(fb);
  is->write("1=25%");
  
  // Main infinite loop used to execute keystroke-based actions
  /*  while (1)
    {

      usleep(20000);
    }
  */

  // DESTROY TIME
  delete motorFL;
  delete motorFR;
  delete motorBL;
  delete motorBR;

  return (0);
}
