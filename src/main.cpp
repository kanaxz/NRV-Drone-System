
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

  
  motorFL = new Motor(17); // Instanciates the motor from GPIO 17
  motorFR = new Motor(17); // Instanciates the motor from GPIO 17
  motorBL = new Motor(17); // Instanciates the motor from GPIO 17
  motorBR = new Motor(17); // Instanciates the motor from GPIO 17

  // Open the device in non-blocking mode
  int fd = open("/dev/ttyPA1", O_RDWR | O_NONBLOCK);

  /*
  if(fd < 0)
      ;  // handle error
  */
  // Try to write some data
  ssize_t written = write(fd, "1=25%", 5);
 
  if(written >= 0){
  
  }

  /*
      ;  // handle successful write (which might be a partial write!)
  else if(errno == EWOULDBLOCK)
      ;  // handle case where the write would block
  else
      ;  // handle real error
  */
  // Reading data is similar
    close(fd);

  // DESTROY TIME
  delete motorFL;
  delete motorFR;
  delete motorBL;
  delete motorBR;

  return (0);
}
