#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &that);
	Cat &operator=(const Cat &that);
	~Cat();

	void makeSound() const;
};
