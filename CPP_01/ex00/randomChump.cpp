#include <string>
#include "Zombie.hpp"

void randomChump (std::string name)
{
	Zombie random_zombie = Zombie(name);
	random_zombie.announce();
}
