#pragma once
#include <ostream>
class Fixed {
public:
	Fixed();
	Fixed(const int i);
	Fixed(const float f);
	Fixed(const Fixed &obj);
	Fixed &operator=(const Fixed &that);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int raw);
	float toFloat( void ) const;
	int toInt( void )const;
private:
	int f_p;
	static const int f_bits;

};

std::ostream &operator<<(std::ostream &out, const Fixed &that);
