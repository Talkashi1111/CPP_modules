#pragma once

class Fixed {
public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed &operator=(const Fixed &that);
	~Fixed(void);

	int getRawBits(void) const;
	void setRawBits(const int raw);
private:
	int f_p;
	static const int f_bits;

};
