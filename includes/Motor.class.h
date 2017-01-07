
#ifndef _MOTOR_H_
#define _MOTOR_H_





class Motor
{

private:

	int servoNumber;
public:
    Motor(int servoNumber);
    ~Motor(void);
    void start(void);

};

#endif /* _MOTOR_H_ */