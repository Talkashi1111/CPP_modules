#include "Base.hpp"
#include "A.hpp"
#include <iostream>
A::A() {
	std::cout << "A constructor" << std::endl;
}

A::~A() {
	std::cout << "A destructor" << std::endl;
}
