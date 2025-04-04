#include "DiamondTrap.hpp"
#include <iostream>
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->name = name + "_clap_name";
	this->hit_points_ = FragTrap::hit_points_;
	this->energy_p_ = ScavTrap::energy_p_;
	this->attack_demage_ = FragTrap::attack_demage_;

	std::cout<<"DiamondTrap Constructor called for " <<this->getName()<< std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &obj) :ClapTrap(obj), FragTrap::FragTrap(obj), ScavTrap::ScavTrap(obj)
{
	this->name = obj.name;
	std::cout << "DiamondTrap copy constructor called for "<< this->name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &that)
{
	if (this != &that)
	{
		FragTrap::operator=(that);
		ScavTrap::operator=(that);
		this->name = that.name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap distructor called for "<< FragTrap::getName() << std::endl;
}

std::string DiamondTrap::getDiamondName()
{
	return (this->name);
}

void DiamondTrap::attack(const std::string &target)
{
	std::cout << " DiamondTrap attack called on " << this->name << std::endl;
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}
