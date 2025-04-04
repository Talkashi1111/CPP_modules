#pragma once
#include <string>

class ClapTrap
{
public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &obj);
	ClapTrap &operator=(const ClapTrap &that);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	std::string getName() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
	int getAttackDamage() const;
	void setAttackDamage(int attack_damage);

private:
	std::string name_;
	int hit_points_;
	int energy_p_;
	int attack_demage_;
};
