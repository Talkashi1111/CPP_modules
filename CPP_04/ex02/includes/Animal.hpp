#pragma once
#include <string>

class AAnimal {
public:
AAnimal();
AAnimal(const AAnimal &obj);
AAnimal &operator=(const AAnimal &that);
virtual ~AAnimal();

virtual void makeSound() const = 0;
std::string getType() const;

protected:
	std::string type;
};
