#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}


Cat::Cat(const Cat &that) : Animal(that)
{
	this->type = that.type;
	std::cout << "Cat copy constructor called "<< std::endl;
}

Cat &Cat::operator=(const Cat &that)
{
	if (this != &that)
	{
		this->type = that.type;
		Animal::operator=(that);
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
}
