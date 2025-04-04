#pragma once
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap &obj);
		FragTrap &operator=(const FragTrap &obj);

		void highFivesGuys(void);
	private:
};
