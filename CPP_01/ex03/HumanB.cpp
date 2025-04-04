#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string human_name) : weapon(NULL), name(human_name)
{
	std::cout << "constructor for " << this->name << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "default destructor for " << this->name << std::endl;
}

void HumanB::attack(void) const
{
	std::cout << this->name << " attacks with their";
	if (this->weapon != NULL)
			std::cout << " " << this->weapon->getType();
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
