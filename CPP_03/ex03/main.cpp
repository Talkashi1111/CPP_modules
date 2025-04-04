#include "DiamondTrap.hpp"
#include <iostream>
int main()
{
	DiamondTrap my_d("tal");
	DiamondTrap my_d2(my_d);
	DiamondTrap my_d3("Buldog");
	my_d2 = my_d3;
	my_d2.whoAmI();
	std::cout << "------------------" << std::endl;
	my_d.attack("enemy");
	my_d.takeDamage(10);
	my_d.beRepaired(10);
	my_d.guardGate();
	my_d.highFivesGuys();
	my_d.whoAmI();

	return (0);
}
