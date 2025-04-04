#pragma once

#include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string human_name);
	~HumanB();

	void attack() const;
	void setWeapon(Weapon &weapon);
private:
	Weapon *weapon;
	std::string name;
};
