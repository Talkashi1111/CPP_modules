#pragma once
#include <ostream>
#include <stdexcept>
class Fixed {
public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed &obj);
	Fixed &operator=(const Fixed &that);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(const int raw);
	float toFloat( void ) const;
	int toInt( void )const;
	static Fixed &min( Fixed &,  Fixed &);
	static const Fixed &min(const Fixed &, const Fixed &);
	static Fixed &max( Fixed &,  Fixed &);
	static const Fixed &max(const Fixed &, const Fixed &);

	//operator overloading
	Fixed &operator+=(const Fixed &);
	Fixed &operator-=(const Fixed &);
	Fixed &operator++(); //prefix ++x
	Fixed operator++(int); //posix x++
	Fixed &operator*=(const Fixed &);
	Fixed &operator/=(const Fixed &);

	Fixed &operator--();
	Fixed operator--(int);
private:
	int f_p;
	static const int f_bits;

};

Fixed operator+(const Fixed&, const Fixed&);
Fixed operator-(const Fixed&, const Fixed&);
bool operator==(const Fixed &, const Fixed&);
bool operator!=(const Fixed &, const Fixed&);
bool operator<(const Fixed&, const Fixed&);
bool operator<=(const Fixed&, const Fixed&);
bool operator>(const Fixed&, const Fixed&);
bool operator>=(const Fixed&, const Fixed&);
Fixed operator*(Fixed const &, Fixed const &);
Fixed operator/(Fixed const &, Fixed const &);



std::ostream &operator<<(std::ostream &out, const Fixed &that);
