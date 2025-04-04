#include "HumanA.hpp"
#include <iostream>
HumanA::HumanA(std::string human_name, Weapon &my_wep) : weapon(my_wep) , name(human_name)
{
	std::cout << "constructor for " << this->name << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "default destructor for" << this->name << std::endl;
}

void HumanA::attack(void) const
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
