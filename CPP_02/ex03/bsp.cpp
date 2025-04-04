#include "Point.hpp"
#include <iostream>

float area(const Point &A, const Point &B, const Point &C)
{
	float ret = (A.getX() * ((B.getY() - C.getY()))
		+ B.getX() * (C.getY() - A.getY()) + C.getX() * (A.getY() - B.getY())).toFloat();
	ret /= 2.0f;
	return (ret < 0 ? -ret : ret);
}

bool bsp(const Point &A, const Point &B, const Point &C, const Point &P)
{
	float A1 = area(A, B, P);
	//std::cout << "area size A1 is " << A1 << std::endl;
	float A2 = area(B, C, P);
	//std::cout << " area size A2 is " << A2 << std::endl;
	float A3 = area(C, A, P);
	//std::cout << "area size A3 is " << A3 << std::endl;
	float BigT = area(A, B, C);
	//std::cout << "area size BigT is " << BigT << std::endl;
	std::cout << "A1 + A2 + A3 == BIGT ??\n"<< std::endl;
	std::cout << A1 << " + "<< A2 << " + " << A3 << " == " << BigT << std::endl;
	return (BigT == (A1 + A2 + A3));
}

