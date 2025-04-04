#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) : name_(name), hit_points_(10), energy_p_(10), attack_demage_(0)
{
	std::cout << "constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) : name_(obj.name_),
										  hit_points_(obj.hit_points_),
										  energy_p_(obj.energy_p_),
										  attack_demage_(obj.attack_demage_)
{
	std::cout << "copy constructor called for " << this->name_ << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "copy assignment called for " << this->name_ << std::endl;
	if (this != &obj)
	{
		this->name_ = obj.name_;
		this->hit_points_ = obj.hit_points_;
		this->energy_p_ = obj.energy_p_;
		this->attack_demage_ = obj.attack_demage_;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor called for " << this->name_ << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energy_p_ > 0 && this->hit_points_ > 0)
	{
		std::cout << "ClapTrap " << this->name_ << " attacks " << target
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

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->name_ << " got damage by " << amount << " points" << std::endl;
	this->hit_points_ -= amount;
	if (this->hit_points_ < 0)
		this->hit_points_ = 0;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->hit_points_ += amount;
	this->energy_p_--;
	std::cout << this->name_ << " repared by " << amount << " points" << std::endl;
}

std::string ClapTrap::getName() const
{
	return this->name_;
}

int ClapTrap::getHitPoints() const
{
	return this->hit_points_;
}

int ClapTrap::getEnergyPoints() const
{
	return this->energy_p_;
}

int ClapTrap::getAttackDamage() const
{
	return this->attack_demage_;
}

void ClapTrap::setAttackDamage(int attack_damage)
{
	this->attack_demage_ = attack_damage;
}
