#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap cp1("bad guy");
	ClapTrap cp2("good guy");

	cp1.setAttackDamage(5);
	cp2.setAttackDamage(5);
	cp1.attack(cp2.getName());
	cp2.takeDamage(cp1.getAttackDamage());
	cp2.beRepaired(1);
	std::cout << cp1.getName() << " has " << cp1.getHitPoints() << " hit points, "
			  << cp2.getName() << " has " << cp2.getHitPoints() << " hit points" << std::endl;
	cp2.attack(cp1.getName());
	cp1.takeDamage(cp2.getAttackDamage());
	cp1.beRepaired(1);
	std::cout << cp1.getName() << " has " << cp1.getHitPoints() << " hit points, "
			  << cp2.getName() << " has " << cp2.getHitPoints() << " hit points" << std::endl;
	cp1.attack(cp2.getName());
	cp2.takeDamage(cp1.getAttackDamage());
	std::cout << cp1.getName() << " has " << cp1.getHitPoints() << " hit points, "
			  << cp2.getName() << " has " << cp2.getHitPoints() << " hit points" << std::endl;
	cp1.attack(cp2.getName());
	cp2.takeDamage(cp1.getAttackDamage());
	std::cout << cp1.getName() << " has " << cp1.getHitPoints() << " hit points, "
			  << cp2.getName() << " has " << cp2.getHitPoints() << " hit points" << std::endl;
	cp2.attack(cp1.getName());
}
