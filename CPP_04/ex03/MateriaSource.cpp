#include <iostream>
#include "AMateria.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		source_[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		source_[i] = other.source_[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	std::cout << "MateriaSource assign operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
			source_[i] = other.source_[i];
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (source_[i])
			delete source_[i];
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!source_[i] && m)
		{
			source_[i] = m;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (source_[i] && source_[i]->getType() == type)
			return source_[i]->clone();
	}
	return NULL;
}
