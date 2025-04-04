#pragma once

#include "Fixed.hpp"

class Point
{

public:
	Point();
	Point(const Fixed &, const Fixed &);
	Point(const Point &obj);
	Point &operator=(const Point &that);
	Point &operator+=(const Point &that);
	~Point();

	Fixed getX() const;
	Fixed getY() const;

private:
	// data members
	const Fixed x;
	const Fixed y;
};

float area(const Point &A, const Point &B, const Point &C);
bool bsp(const Point &A, const Point &B, const Point &C, const Point &P);
bool operator==(const Point &, const Point&);
Point operator+(const Point&, const Point&);
