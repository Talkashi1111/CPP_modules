#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(const Cat &that);
	Cat &operator=(const Cat &that);
	~Cat();

	void makeSound() const;

private:
	Brain *brain_ptr;
};
