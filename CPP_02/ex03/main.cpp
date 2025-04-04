#include "Point.hpp"
#include <iostream>
int main()
{
	Point a(Fixed(0), Fixed(10));
	std::cout << "Point a is " << a.getX() << " " << a.getY() << std::endl;
	Point b(30, 5);
	std::cout << "Point b is " << b.getX() << " " << b.getY() << std::endl;
	Point c(20, 40);
	std::cout << "Point c is " << c.getX() << " " << c.getY() << std::endl;
	Point p(10, 20);
	std::cout << "Point p is " << p.getX() << " " << p.getY() << std::endl;

	if (bsp(a, b, c, p))
		std::cout << "point P " << p.getX() << " " << p.getY() << " " << "is inside " << std::endl;
	else
		std::cout << " \nis not inside \n";
	Point d(-10, 20);
	std::cout << "Point d is " << d.getX() << " " << d.getY() << std::endl;
	Point e(40, 100);
	std::cout << "Point e is " << e.getX() << " " << e.getY() << std::endl;

	if (bsp(d, e, a, p))
		std::cout << "point P " << p.getX() << " " << p.getY() << " " << "is inside " << std::endl;
	else
		std::cout << " \nis not inside \n";
}
