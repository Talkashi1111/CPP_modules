#include <iostream>
#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called for " << this->getType() << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other)
{
	std::cout << "Ice copy constructor called for " << this->getType() << std::endl;

}

Ice &Ice::operator=(Ice const &other)
{
	std::cout << "Ice assign operator called for " << this->getType() << std::endl;
	if (this != &other)
		this->AMateria::operator=(other);
	return *this;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called for " << this->getType() << std::endl;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
