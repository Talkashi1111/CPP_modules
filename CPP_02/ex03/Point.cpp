#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Fixed &x, const Fixed &y) : x(x), y(y) {}

Point::Point(const Point &obj) : x(obj.x), y(obj.y) {}

Point &Point::operator=(const Point &that)
{
	if (this != &that)
	{
		(Fixed) this->x = that.x;
		(Fixed) this->y = that.y;
	}
	return (*this);
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}

bool operator==(const Point &a, const Point &b)
{
	return (a.getX() == b.getX() && a.getY() == b.getY());
}

Point &Point::operator+=(const Point& that)
{
	(Fixed) this->x += that.getX();
	(Fixed) this->y += that.getY();
	return (*this);
}

Point operator+(const Point &a, const Point &b)
{
	Point ret(a);
	ret += b;
	return (ret);
}
Point::~Point(){};
