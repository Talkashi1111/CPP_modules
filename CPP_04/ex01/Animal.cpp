#include "Animal.hpp"
#include <iostream>
Animal::Animal()
{
	this->type = "";
	std::cout << "Animal default constructor is called" << std::endl;
}

Animal::Animal(const Animal &obj)
{
	this->type = obj.type;
	std::cout << "Animal copy constructor called " << std::endl;
}

Animal &Animal::operator=(const Animal &that)
{
	if (this != &that)
	{
		this->type = that.type;
	}
	std::cout << "Animal copy assignment is called " << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const{

}
