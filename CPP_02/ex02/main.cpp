#include "Fixed.hpp"
#include <iostream>
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;

/*
Fixed c(10);
Fixed d(20);

Fixed e = Fixed::min(c, d);
std::cout << e << std::endl;
Fixed f = d - c;
std::cout << f << std::endl;
f++;
std::cout << f << std::endl;
std::cout << f.toInt() << std::endl;
f++;
std::cout << f << std::endl;
Fixed g = f / 5;
std::cout << g.toInt() << std::endl;
std::cout << g.toFloat() << std::endl;
std::cout << g << std::endl; */
return 0;
}
