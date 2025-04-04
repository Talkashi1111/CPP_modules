#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal constructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &that)
{
	this->type = that.type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &that)
{
	if (this != &that)
	{
		this->type = that.type;
	}
	std::cout << "WrongAnimal copy assignment called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
