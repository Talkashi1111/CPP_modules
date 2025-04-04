#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public  FragTrap, public  ScavTrap
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &obj);
		DiamondTrap &operator=(const DiamondTrap &that);
		~DiamondTrap();

		std::string getDiamondName();
		void attack(const std::string &target);
		void whoAmI();
	private:
	std::string name;
};
