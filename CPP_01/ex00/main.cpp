#include <string>
#include <iostream>
#include "Zombie.hpp"



void func_outside(const Zombie &some_zombie)
{
	std::cout << "adress of some_zombie: " << &some_zombie << std::endl;
}

int main(void)
{
	Zombie* z = newZombie("Zombie_Name");
	z->announce();
	std::cout << "adress of z: " << z << std::endl;
	func_outside(*z);
	randomChump("Julia");
	delete z;//what is the order of the distructor and is it a problem if i delete and than call default destructor?
	return 0;
}
