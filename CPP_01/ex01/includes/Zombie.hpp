#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie
{
public:
	Zombie(std::string name);
	Zombie();
	~Zombie(void);
	void announce(void);
	void setName(std::string name);

private:
	std::string zombie_name_;
};

Zombie*	zombieHorde( int N, std::string name );
#endif
