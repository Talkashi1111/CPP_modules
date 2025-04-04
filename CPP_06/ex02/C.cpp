#include "C.hpp"
#include "Base.hpp"
#include <iostream>

C::C() {
	std::cout << "C constructor" << std::endl;
}

C::~C() {
	std::cout << "C destructor" << std::endl;
}
