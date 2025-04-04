#include "whatever.hpp"

Awesome::Awesome(int n) : _n(n)
{
	this->_s = (char)n + 5 + " is awesome";
	std::cout << "Awesome constructor called" << std::endl;
}
Awesome::Awesome(const Awesome &other) : _n(other._n), _s(other._s) {}

Awesome &Awesome::operator=(const Awesome &other)
{
	if (this != &other)
	{
		this->_n = other._n;
		this->_s = other._s;
	}
	return *this;
}

Awesome::~Awesome() {}
std::string Awesome::get_s() const { return this->_s; }
float Awesome::get_f() const { return this->_f; }





int main(void)
{
	int a = 2;
	int b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
/*
	char ptr1[] = "hello";
	char ptr2[] = "world";

	char *p1 = ptr1;
	char *p2 = ptr2;

	std::cout << "p1 = " << p1 << ", p2 = " << p2 << std::endl;
	::swap(p1, p2);
	std::cout << "after swap" << std::endl;
	std::cout << "p1 = " << p1 << ", p2 = " << p2 << std::endl;

	Awesome my_awesome(50);
	Awesome my_awesome2;
	std::cout << "my awesome name is " << my_awesome.get_s() << std::endl;
	std::cout << "my awesome2 name is " << my_awesome2.get_s() << std::endl;
	::swap(my_awesome, my_awesome2);
	std::cout << "after swap" << std::endl;
	std::cout << "my awesome name is " << my_awesome.get_s() << std::endl;
	std::cout << "my awesome2 name is " << my_awesome2.get_s() << std::endl; */
	return 0;
}
