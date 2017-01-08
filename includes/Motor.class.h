
#ifndef _MOTOR_H_
#define _MOTOR_H_





class Motor
{

private:
	FILE *fp;
	int servoNumber;
	void start(void);
	void stop(void);
public:
    Motor(int servoNumber);
    ~Motor(void);

    void setValue(int value);

};

#endif /* _MOTOR_H_ */