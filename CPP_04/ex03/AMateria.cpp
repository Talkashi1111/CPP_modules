#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type_(type)
{
	std::cout << "AMateria constructor called for " << type << std::endl;
}

AMateria::AMateria(AMateria const &other)
{
	std::cout << "AMateria copy constructor called for " << other.getType() << std::endl;
	type_ = other.getType();
}

AMateria &AMateria::operator=(AMateria const &other)
{
	std::cout << "AMateria assign operator called for " << other.getType() << std::endl;
	if (this != &other)
		type_ = other.getType();
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called for " << type_ << std::endl;
}

std::string const &AMateria::getType() const
{
	return type_;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria use called for " << type_ << "on target " << target.getName() << std::endl;
}
