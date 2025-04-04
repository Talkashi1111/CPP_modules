#pragma once

#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(std::string name, Weapon &my_wep);
	~HumanA(void);
	void attack() const;

private:
	Weapon &weapon;
	std::string name;
};
