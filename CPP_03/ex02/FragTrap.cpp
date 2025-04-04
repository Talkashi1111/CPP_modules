#include "FragTrap.hpp"
#include <iostream>
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_points_ = 100;
	this->energy_p_ = 100;
	this->attack_demage_ = 30;
	std::cout << "FragTrap constructor called for " << this->name_ << std::endl;
}
FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "FragTrap copy constructor called for " << this->name_ << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &that)
{
	if (this != &that)
	{
		ClapTrap::operator=(that);
	}
	std::cout << "FragTrap assignation operator called for " << this->name_ << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << this->name_ << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name_ << " requested a high fives and got my highfives! " << std::endl;
}
