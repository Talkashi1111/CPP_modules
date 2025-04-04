#include "Animal.hpp"
#include <iostream>
AAnimal::AAnimal()
{
	this->type = "";
	std::cout << "Animal default constructor is called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj)
{
	this->type = obj.type;
	std::cout << "Animal copy constructor called " << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &that)
{
	if (this != &that)
	{
		this->type = that.type;
	}
	std::cout << "Animal copy assignment is called " << std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}

void AAnimal::makeSound() const{

}
