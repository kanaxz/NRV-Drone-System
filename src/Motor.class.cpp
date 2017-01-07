
#include "Motor.class.hpp"

/*
** Accessors
*/
std::string Motor::getName(void) const
{
	return (this->name);
}

int Motor::getPosX(void) const
{
	return (this->pos.x);
}

int Motor::getPosY(void) const
{
	return (this->pos.y);
}

int Motor::getHp(void) const
{
	return (this->hp);
}

int Motor::getMaxHp(void) const
{
	return (this->maxhp);
}

int Motor::getScore(void) const
{
	return (this->score);
}

int Motor::getDmg(void) const
{
	return (this->dmg);
}

/*
**  Setters
*/
void	Motor::setAnnounce(std::string announce)
{
	this->txtannounce = announce;
}

void	Motor::setAutoAttack()
{
	this->autoattack = (this->autoattack) ? 0 : 1;
}

/*
** Methods
*/
void    Motor::bulletHit(ABullet *bullet)
{
    t_point bulletpos;

    bulletpos = bullet->getPos();
	if (bulletpos.x >= this->pos.x - 3 &&
		bulletpos.x <= this->pos.x + 10 &&
		bulletpos.y >= this->pos.y - 2 &&
		bulletpos.y <= this->pos.y + 2)
		this->takeDamage(bullet->getDamage());
}

void Motor::sendUnkillableFriend(void)
{
	return ;
}

void Motor::addScore(int score)
{
	this->score += score;
}

void Motor::moveUp(void)
{
	if (this->pos.y > 0)
		this->pos.y--;
}

void Motor::moveDown(t_point winsize)
{
	if (this->pos.y < winsize.y - 1)
		this->pos.y++;
}

void Motor::moveLeft(void)
{
	if (this->pos.x > 0)
		this->pos.x--;
}

void Motor::moveRight(t_point winsize)
{
	if (this->pos.x < winsize.x - 4)
		this->pos.x++;
}

void Motor::saysth(void) const
{
	std::cout << "\033[36m" << this->name << "\033[0m"<< " : "
			  << Motor::quotes[5 + rand() % 48] << std::endl;
}

void Motor::show(void) const
{
	// Show ship
	attron(COLOR_PAIR(2));
	mvprintw(this->pos.y - 2, this->pos.x,	"|\\");
	mvprintw(this->pos.y - 1, this->pos.x,	"| \\");
	mvprintw(this->pos.y, this->pos.x,		"|  }");
	mvprintw(this->pos.y + 1, this->pos.x,	"| /");
	mvprintw(this->pos.y + 2, this->pos.x,	"|/");
	attroff(COLOR_PAIR(2));
	// Show life
	attron(COLOR_PAIR(0));
	mvprintw(1, 1,	"Player : %s", this->getName().c_str());
	mvprintw(2, 1,	"Life   : %i / %i", this->getHp(), this->getMaxHp());
	mvprintw(3, 1,	"Damage : %i", this->getDmg());
	mvprintw(4, 1,	"Score  : %i", this->getScore());
	attroff(COLOR_PAIR(0));
}

void Motor::attack(void)
{
	if (this->autoattack)
		this->bullets->add(this->name, this->dmg,
						   this->pos.x + 4, this->pos.y, 1);
}

int Motor::takeDamage(unsigned int amount)
{
	if (this->hp > 0)
	{
		if (this->hp > (int)amount)
			this->hp -= amount;
		else
			this->hp = 0;
		this->txtannounce = this->name + " takes " + std::to_string(amount) + "damage. (" + std::to_string(this->hp) + "HP left)";
		if (this->hp == 0)
			this->txtannounce = this->name + " just died.";
	}
	else
		this->txtannounce = this->name + " is dead.";
	return (amount);
}

void Motor::introduce(void) const
{
	std::cout << "I am " << this->name
			  << " and i love pooonieees!!!" << std::endl;
}

void Motor::announce(void)
{
	t_point winsize;
	int		start;
	int		end;

	start = rand();
	if (start % 1000 == 1)
		this->setAnnounce(quotes[start % 48]);
	getmaxyx(stdscr, winsize.y, winsize.x);
	start = (winsize.x - this->txtannounce.length()) / 2;
	end = start + this->txtannounce.length() + 2;
	mvprintw(1, start + 2, this->txtannounce.c_str());
	attron(COLOR_PAIR(3));
	mvprintw(0, start, "+-");
	mvprintw(1, start, "| ");
	mvprintw(2, start, "+-");
	while (++start < end)
	{
		mvprintw(0, start, "-");
		mvprintw(2, start, "-");
	}
	mvprintw(0, start, "-+");
	mvprintw(1, start, " |");
	mvprintw(2, start, "-+");
	attroff(COLOR_PAIR(3));
}

/*
** Operators
*/
Motor &Motor::operator=(Motor const &copy)
{
	this->name = copy.getName();
	this->hp = copy.getHp();
	this->maxhp = copy.getMaxHp();
	this->score = copy.getScore();
	this->dmg = copy.getDmg();
	this->bullets = copy.bullets;
	this->unkillablefriend = copy.unkillablefriend;
	this->autoattack = 0;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Motor &a)
{
	os << a.getName() << " has " << a.getHp()
	   << "HP and is unarmed." << std::endl;
	return (os);
}

/*
** Constructeurs / Destructeurs
*/
Motor::Motor(std::string const &name, BulletHandler *bullets) : name(name), bullets(bullets)
{
	srand((long)time(0));
	this->hp = 100;
	this->maxhp = 100;
	this->score = 0;
	this->dmg = 10;
	getmaxyx(stdscr, this->pos.y, this->pos.x);
	this->pos.y /= 2;
	this->pos.x /= 5;
	this->unkillablefriend = 3;
	this->autoattack = 0;
	std::cout << "\033[32m" << this->name
			  << ", is born.\033[0m"
			  << std::endl;
}

Motor::Motor(Motor const &a)
{
	srand((long)time(0));
	this->hp = a.getHp();
	this->name = a.getName();
	this->maxhp = a.getMaxHp();
	this->score = a.getScore();
	this->dmg = a.getDmg();
	this->pos = a.pos;
	this->bullets = a.bullets;
	this->unkillablefriend = 3;
	this->autoattack = 0;
	std::cout << "\033[32m" << this->name
			  << ", is born.\033[0m"
			  << std::endl;
}

Motor::Motor(Motor const &a, std::string name) : name(name)
{
	srand((long)time(0));
	this->hp = a.getHp();
	this->maxhp = a.getMaxHp();
	this->score = a.getScore();
	this->dmg = a.getDmg();
	this->pos = a.pos;
	this->bullets = a.bullets;
	this->unkillablefriend = 3;
	this->autoattack = 0;
	std::cout << "\033[32m" << this->name
			  << " bought a ship.\033[0m"
			  << std::endl;
}

Motor::~Motor (void)
{
	std::cout << "\033[31mYour ship, " << this->name
			  << ", is dead. You're alone now. Feel free to kill yourself.\033[0m"
			  << std::endl;
}
