
#ifndef _BRAIN_H_
#define _BRAIN_H_

#include "MPU6050.class.h"
#include "Motor.class.h"
#include "PID.class.h"

class Brain
{

private:

public:
    Brain();
    ~Brain();



    void start(void);

};

#endif /* _BRAIN_H_ */
