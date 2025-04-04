#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout << "Brain constructor called" << std::endl;

}

Brain::Brain(const Brain &obj) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = obj;//using the assignmnet operator implemented down to copy the ideas
}

Brain &Brain::operator=(const Brain &obj)
{
	std::cout << "Brain copy assignmnet called" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = obj.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
