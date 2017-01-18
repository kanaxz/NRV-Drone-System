
#include "Motor.class.h"
#include "unistd.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "MPU6050.h"
#include <iomanip>

int main(void)
{ 
  
  //Brain brain;
  // Open the device in non-blocking mode
  
  MPU6050 imu;
  imu.bypassDrift();
  float ypr[3];
  while(true) {
        if(imu.getFIFOCount() > 42) {
            imu.getYawPitchRoll(ypr);
            std::cout << std::fixed << std::setprecision(3) << "YAW:"<<ypr[0]<<std::endl;
        }
  }

  
 
  
 



  return (0);
}
