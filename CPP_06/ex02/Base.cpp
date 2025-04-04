#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base() {
	// Destructor implementation
}

void identify(Base *p)
{
	std::cout << "Identify by pointer" << std::endl;
	if (dynamic_cast<A *>(p) != 0)
		std::cout << "A class was dynamically cast successfully" << std::endl;
	else if (dynamic_cast<B*>(p) != 0)
		std::cout << "B class was dynamically cast successfully" << std::endl;
	else if (dynamic_cast<C*>(p) != 0)
		std::cout << "C class was dynamically cast successfully" << std::endl;
	else
		std::cout << "Class was not dynamically cast" << std::endl;
}

/**
 * @brief Identifies the derived class type of the given Base reference.
 *	using function overloading, this function will be called when a reference is passed.
 *	in our example Base is abstract so we can only pass a dereference to an adress of a derieved class
 *
 */
void identify(Base &p)
{
	std::cout << "Identify by reference" << std::endl;
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A class was dynamically cast successfully" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "A class was not dynamically cast" << std::endl;
	}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "B class was dynamically cast successfully" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "B class was not dynamically cast" << std::endl;
	}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "C class was dynamically cast successfully" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "C class was not dynamically cast" << std::endl;
	}
}

Base *generate(void)
{
	std::srand(time(NULL));
	int random = rand() % 3;
	Base *ret_class = NULL;
	if (random == 0)
	{
		ret_class = new A();
		return ret_class;
	}
	else if (random == 1)
	{
		ret_class = new B();
		return ret_class;
	}
	else
	{
		ret_class = new C();
		return ret_class;
	}
	return NULL;
}

