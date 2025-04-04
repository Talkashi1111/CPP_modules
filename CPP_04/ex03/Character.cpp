#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"

Character::Character(std::string const &name) : name_(name)
{
	std::cout << "Character constructor called for " << name << std::endl;
	for (int i = 0; i < 4; i++)
		inventory_[i] = NULL;
}

Character::Character(Character const &obj)
{
	std::cout << "Character copy constructor called for " << obj.getName() << std::endl;
	name_ = obj.getName();
	for (int i = 0; i < 4; i++)
		inventory_[i] = obj.inventory_[i];
}

Character &Character::operator=(Character const &obj)
{
	std::cout << "Character assign operator called for " << obj.getName() << std::endl;
	if (this != &obj)
	{
		name_ = obj.getName();
		for (int i = 0; i < 4; i++)
			inventory_[i] = obj.inventory_[i];
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called for " << name_ << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inventory_[i])
			delete inventory_[i];
	}
}

std::string const &Character::getName() const
{
	return name_;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory_[i])
		{
			inventory_[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		inventory_[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && inventory_[idx])
		inventory_[idx]->use(target);
}
