#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
int main()
{
	ScavTrap scav("scarlet");
	FragTrap frag("Freud");

	scav.attack("Freud");
	frag.attack("scarlet");
	frag.takeDamage(frag.getAttackDamage());
	scav.takeDamage(scav.getAttackDamage());
	std::cout << scav.getName() <<"ScavTrap energy points: " << scav.getEnergyPoints() << std::endl;
	std::cout << frag.getName() <<"FragTrap energy points: " << frag.getEnergyPoints() << std::endl;
	scav.guardGate();
	frag.highFivesGuys();
	return (0);
}
