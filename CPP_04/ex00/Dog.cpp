#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}


Dog::Dog(const Dog &that) : Animal(that)
{
	this->type = that.type;
	std::cout << "Dog copy constructor called "<< std::endl;
}

Dog &Dog::operator=(const Dog &that)
{
	if (this != &that)
	{
		this->type = that.type;
		Animal::operator=(that);
	}
	std::cout << "Dog copy assignment called" << std::endl;
	return (*this);
}

void Dog::makeSound()const
{
	std::cout << "Waf Waf" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called \n";
}


