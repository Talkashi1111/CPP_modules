#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &obj);
	ScavTrap &operator=(const ScavTrap &obj);
	~ScavTrap();

	void attack(const std::string &target);
	void guardGate();

};
