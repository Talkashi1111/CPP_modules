#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	std::string name_;
	AMateria *inventory_[4];

public:
	Character(std::string const &name);
	Character(Character const &obj);
	Character &operator=(Character const &obj);
	~Character();

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};
