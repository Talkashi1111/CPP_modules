#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::f_bits = 8;

Fixed::Fixed()
{
	this->f_p = 0;
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int i){
	this->f_p = i << this->f_bits;
	std::cout << "Int constructor called" << std::endl;};

Fixed::Fixed(const float f)
{
	this->f_p = roundf(f * (1<<f_bits));
	std::cout << "Float constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->f_p = obj.f_p;
}

Fixed &Fixed::operator=(const Fixed &that)
{
	if (this != &that)
	{
		std::cout << "Copy assignment operator called"<< std::endl;
		//std::cout << "copy assignement called for adress" << this << std::endl;
		this->f_p = that.f_p;
	}
	return (*this);
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

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
float Fixed::toFloat( void ) const
{
	float ret = static_cast<float>(this->f_p) / static_cast<float>(1 << this->f_bits);
	return (ret);
}

int Fixed::toInt( void )const
{
	return (this->f_p >> this->f_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
