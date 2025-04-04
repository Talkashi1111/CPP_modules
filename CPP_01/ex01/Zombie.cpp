#include "Zombie.hpp"
#include <string>
#include <iostream>

Zombie::Zombie(std::string name) : zombie_name_(name)
{ std::cout <<"constructor called for "<< this->zombie_name_ << std::endl;}

Zombie::Zombie(void) {std::cout << "Default constructor called "<< this->zombie_name_ << std::endl;}

Zombie::~Zombie(void){ std::cout << "destructor called for "<< this->zombie_name_ <<std::endl;}

void Zombie::announce(void)
{
	std::cout << zombie_name_ << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
	zombie_name_ = name;
}


