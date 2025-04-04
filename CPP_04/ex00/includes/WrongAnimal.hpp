#pragma once
#include <string>

class WrongAnimal{
public:
WrongAnimal();
WrongAnimal(const WrongAnimal &obj);
WrongAnimal &operator=(const WrongAnimal &that);
~WrongAnimal();

void makeSound() const;

protected:
std::string type;
};
