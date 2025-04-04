#include "Base.hpp"
#include <iostream>
#include <unistd.h>
void identify(Base *p);
void identify(Base &p);
Base *generate(void);

int main()
{
	Base *my_base = generate();
	identify(my_base);
	try
	{
		identify(*my_base);
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}
	std::cout << "---------------------------------------------------------------------" << std::endl;
	sleep(1);
	Base *another_base = generate();
	std::cout << "Adress of another base using another_base: " << another_base << std::endl;
	std::cout << "Adress of dereference another base using &(*another_base): " << &(*another_base) << std::endl;
	identify(another_base);
	try
	{
		identify(*another_base); // dereference another_base that will point to the same object as my_base
	}
	catch (...)
	{
		std::cout << "Error" << std::endl;
	}
	delete another_base;
	delete my_base;
	return 0;
}
