#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	this->type = "Cat";
	this->brain_ptr = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}


Cat::Cat(const Cat &that) : AAnimal(that)
{
	this->type = that.type;
	this->brain_ptr = new Brain(*that.brain_ptr);
	std::cout << "Cat copy constructor called "<< std::endl;
}

Cat &Cat::operator=(const Cat &that)
{
	if (this != &that)
	{
		this->type = that.type;
		AAnimal::operator=(that);
		if (this->brain_ptr != 0)
			delete this->brain_ptr;
		this->brain_ptr = new Brain(*that.brain_ptr);
	}
	std::cout << "Cat copy assignment called" << std::endl;
	return (*this);
}

void Cat::makeSound()const
{
	std::cout << "Miaou Miaou" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called \n";
	delete this->brain_ptr;
}
