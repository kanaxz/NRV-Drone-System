
#ifndef _BRAIN_H_
#define _BRAIN_H_

#include "../MPU6050/MPU6050.class.h"
#include "../motor/Motor.class.h"
#include "../math/PID.class.h"

class Brain
{

private:

public:
    Brain();
    ~Brain();



    void start(void);

};

#endif /* _BRAIN_H_ */