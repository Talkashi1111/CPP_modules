#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <limits>
const int Fixed::f_bits = 8;

Fixed &Fixed::min(Fixed &x, Fixed &y)
{
	if (x == y)
		throw std::runtime_error("Both numbers are equal");
	if (x < y)
		return (x);
	else
		return (y);
}
const Fixed &Fixed::min(const Fixed &x, const Fixed &y)
{
	if (x == y)
		throw std::runtime_error("Both numbers are equal");
	if (x < y)
		return (x);
	else
		return (y);
}

Fixed &Fixed::max(Fixed &x, Fixed &y)
{
	if (x == y)
		throw std::runtime_error("Both numbers are equal");
	if (x > y)
		return (x);
	else
		return (y);
}

const Fixed &Fixed::max(const Fixed &x, const Fixed &y)
{
	if (x == y)
		throw std::runtime_error("Both numbers are equal");
	if (x > y)
		return (x);
	else
		return (y);
}

Fixed::Fixed()
{
	this->f_p = 0;
}
Fixed::Fixed(const int i){
	this->f_p = i << this->f_bits;

}

Fixed::Fixed(const float f)
{
	this->f_p = roundf(f * (1<<f_bits));
}
Fixed::Fixed(const Fixed &obj)
{
	this->f_p = obj.f_p;
}

Fixed &Fixed::operator=(const Fixed &that)
{
	if (this != &that)
	{
		this->f_p = that.f_p;
	}
	return (*this);
}

Fixed &Fixed::operator+=(const Fixed& that)
{
	this->f_p = this->f_p + that.f_p;
	return *this;
}

Fixed operator+(const Fixed& f_1, const Fixed& f_2)
{
	Fixed ret = f_1;
	ret +=f_2;
	return ret;
}



Fixed &Fixed::operator-=(const Fixed& that)
{
	this->f_p = this->f_p - that.f_p;
	return *this;
}

Fixed operator-(const Fixed& f_1, const Fixed &f_2)
{
	Fixed ret = f_1;
	ret -= f_2;
	return ret;
}

Fixed &Fixed::operator++()
{
	this->f_p++;
	return *this;//to fix
}

Fixed Fixed::operator++(int)
{
	Fixed ret = *this;
	this->f_p++;
	return (ret);
}

Fixed &Fixed::operator--()
{
	this->f_p--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed ret = *this;
	this->f_p--;
	return (ret);
}

bool operator==(const Fixed &x, const Fixed &y)
{
	return (y.getRawBits() == x.getRawBits());
}

bool operator!=(const Fixed &x, const Fixed &y)
{
	return !(y == x);
}

bool operator<(const Fixed &x, const Fixed &y)
{
	return (y.getRawBits() > x.getRawBits());
}

bool operator<=(const Fixed &x, const Fixed &y)
{
	return !(x > y);
}

bool operator>(const Fixed &x, const Fixed &y)
{
	return (y < x);
}

bool operator>=(const Fixed &x, const Fixed &y)
{
	return !(x < y);
}


Fixed::~Fixed() { }

int Fixed::getRawBits(void) const
{
	return this->f_p;
}

void Fixed::setRawBits(const int raw)
{
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

Fixed &Fixed::operator*=(const Fixed &that)
{
	long long resault = this->f_p* that.f_p;

	// Shift back down to account for the fixed-point representation
	resault >>= this->f_bits;
	if (resault > std::numeric_limits<int>::max() || resault < std::numeric_limits<int>::min())
		throw std::overflow_error("Multiplication overflow.");
	this->f_p = static_cast<int>(resault);
	return *this;
}

Fixed operator*(const Fixed &x, const Fixed &y)
{
	Fixed ret = x;
	try {
		ret *= y;
	}
	catch (std::overflow_error &e)
	{
		std::cout << e.what() << std::endl;
		throw;
	}
	return ret;
}

Fixed &Fixed::operator/=(const Fixed &that)
{
	if (that.getRawBits() == 0)
	{
		std::cout << "division by zero is not accepted" << std::endl;
		throw std::runtime_error("Math error: Attempted to divide by Zero\n");
	}
	long long resault = this->toFloat() / that.toFloat();
	resault <<= this->f_bits;
	if (resault > std::numeric_limits<int>::max() || resault < std::numeric_limits<int>::min())
		throw std::overflow_error("Division overflow.");
	this->f_p = static_cast<int>(resault);
	return *this;
}

Fixed operator/(Fixed const &x, Fixed const &y)
{
	Fixed ret = x;
	try {
		ret /= y;
	}
	catch (std::overflow_error &e)
	{
		std::cout << e.what() << std::endl;
		throw;
	}
	return ret;
}


std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
