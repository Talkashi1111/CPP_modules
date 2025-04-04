#include "Weapon.hpp"
#include <iostream>


Weapon::Weapon(std::string w_name): type(w_name){std::cout << "default constructor called for "<< this->getType() << std::endl;}
Weapon::~Weapon () {std::cout << "default destructor " << this->getType() << std::endl;}
//Weapon::Weapon(){};

const std::string &Weapon::getType() const {
	return (this->type);
}

void Weapon::setType(std::string new_type) {
	type = new_type;
}
