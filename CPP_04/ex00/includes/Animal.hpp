#pragma once
#include <string>

class Animal {
public:
Animal();
Animal(const Animal &obj);
Animal &operator=(const Animal &that);
virtual ~Animal();

virtual void makeSound() const;
std::string getType() const;

protected:
	std::string type;
};
