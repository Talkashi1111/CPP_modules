#pragma once
#include "Brain.hpp"
#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(const Dog &that);
	Dog &operator=(const Dog &that);

	~Dog();

	void makeSound() const;

	private:
	Brain *brain_ptr;
};
