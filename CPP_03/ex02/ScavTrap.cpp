#include "ScavTrap.hpp"
#include <iostream>
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	//to ask: how to call to ClapTrap constructor ?
	this->hit_points_ = 100;
	this->energy_p_ = 50;
	this->attack_demage_ = 20;
	std::cout << "ScavTrap constructor called for " << this->name_ << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap copy constructor is called for " << this->getName() << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
	if (this != &obj)// why not obj ?
	{
		std::cout << "ScavTrap assignement operator called \n";
		ClapTrap::operator=(obj);
	}
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap destructor called for " << this->getName() << std::endl;
}

void ScavTrap::attack (const std::string &target)
{
		if (this->energy_p_ > 0 && this->hit_points_ > 0)
	{
		std::cout << "ScavTrap " << this->name_ << " attacks " << target
				  << ", causing " << this->attack_demage_ << " points of damage!" << std::endl;
		this->energy_p_--;
	}
	else
	{
		if (this->energy_p_ <= 0)
			std::cout << this->name_ << " hasn't enough energy" << std::endl;
		if (this->hit_points_ <= 0)
			std::cout << this->name_ << " hasn't enough hit points" << std::endl;
	}
}

void ScavTrap::guardGate ()
{
	std::cout << " ScavTrap " << this->getName() <<" is now in Gate keeper mode " << std::endl;
}
