#include <iostream>
#include "ICharacter.hpp"
#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called for " << this->getType() << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other)
{
	std::cout << "Cure copy constructor called for " << this->getType() << std::endl;

}

Cure &Cure::operator=(Cure const &other)
{
	std::cout << "Cure assign operator called for " << this->getType() << std::endl;
	if (this != &other)
		this->AMateria::operator=(other);
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called for " << this->getType() << std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
