#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	this->type = "Dog";
	this->brain_ptr = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}


Dog::Dog(const Dog &that) : AAnimal(that)
{
	this->type = that.type;
	this->brain_ptr = new Brain(*that.brain_ptr);
	std::cout << "Dog copy constructor called "<< std::endl;
}

Dog &Dog::operator=(const Dog &that)
{
	if (this != &that)
	{
		this->type = that.type;
		AAnimal::operator=(that);
		if (this->brain_ptr != 0)
			delete this->brain_ptr;
		this->brain_ptr = new Brain(*that.brain_ptr);
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
	delete this->brain_ptr;
	std::cout << "Dog destructor called \n";
}


