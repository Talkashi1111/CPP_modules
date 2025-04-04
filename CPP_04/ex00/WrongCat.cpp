#include "WrongCat.hpp"
#include <iostream>
WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &that) : WrongAnimal(that)
{
	this->type = that.type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &that)
{
	if (this != &that)
	{
		this->type = that.type;
		WrongAnimal::operator=(that);
	}
	std::cout << "WrongCat copy assignment called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Miaow Miaow Wrong cat" << std::endl;
}

