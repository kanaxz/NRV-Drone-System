
#ifndef MOTOR_HPP
#define MOTOR_HPP

#include <iostream>


class Motor
{
protected:
	std::string			name;
	std::string			txtannounce;
	int					unkillablefriend;
	t_point				pos;
	int					hp;
	int					maxhp;
	int					score;
	int					dmg;
	bool				autoattack;
	static std::string	quotes[];
 	inline Motor(void) {std::cout << "Dont use me";};

public:
// Getters
	std::string			getName(void) const;
	int					getHp(void) const;
	int					getPosX(void) const;
	int					getPosY(void) const;
	int					getMaxHp(void) const;
	int					getScore(void) const;
	int					getDmg(void) const;

// Setters
	void				setAnnounce(std::string announce);
	void				setAutoAttack(void);

// Methods
	void bulletHit(ABullet *bullet);
	void sendUnkillableFriend(void);
	void addScore(int score);
	void moveUp(void);
	void moveDown(t_point winsize);
	void moveLeft(void);
	void moveRight(t_point winsize);
	void show(void) const;
    void attack(void);
	int	 takeDamage(unsigned int amount);
	void announce(void);
	void introduce(void) const;
	void saysth(void) const;

// Operators
	Motor &operator=(Motor const &copy);

// Constructors / Destructors
	Motor(std::string const &name);
	Motor(Motor const &a);
	Motor(Motor const &a, std::string name);
	virtual ~Motor(void);
};

std::ostream &operator<<(std::ostream &os, const Motor &a);


#endif
