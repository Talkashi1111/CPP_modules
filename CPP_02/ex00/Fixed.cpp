#include "Fixed.hpp"
#include <iostream>

const int Fixed::f_bits = 8;

Fixed::Fixed()
{
	this->f_p = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->f_p = obj.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &that)
{
	if (this != &that)
	{
		std::cout << "Copy assignment operator called"<< std::endl;
		this->f_p = that.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() { std::cout << "Default distructor called" << std::endl; }

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->f_p;
}

void Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called " << std::endl;
	this->f_p = raw;
}
