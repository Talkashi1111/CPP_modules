#include "ScavTrap.hpp"
#include <iostream>
int main(void)
{
	ClapTrap evil("Drakula");
	ScavTrap st("good guy");
	std::cout<< " good guy hit points: " << st.getHitPoints() << std::endl;
	std::cout << " good guy energy points: " << st.getEnergyPoints() << std::endl;
	std::cout << " Drakula hit points: " << evil.getHitPoints() << std::endl;
	std::cout << " Drakula energy points: " << evil.getEnergyPoints() << std::endl;
	st.setAttackDamage(4);
	evil.attack("good guy");
	st.attack("Drakula");
	st.takeDamage(evil.getAttackDamage());
	st.beRepaired(10);
	std::cout << " good guy hit points: " << st.getHitPoints() << std::endl;
	evil.takeDamage(st.getAttackDamage());
	std::cout << " Drakula hit points: " << evil.getHitPoints() << std::endl;
	st.guardGate();
	return (0);

}
