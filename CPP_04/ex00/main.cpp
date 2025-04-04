#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal *animal = new Animal();
	const Animal *poudel = new Dog();
	const Animal *minou = new Cat();
	std::cout << poudel->getType() << " " << std::endl;
	std::cout << minou->getType() << " " << std::endl;
	minou->makeSound(); // will output the cat sound!
	poudel->makeSound();
	animal->makeSound();

	WrongAnimal *wrongAnimal = new WrongAnimal();
    WrongAnimal *wrongCat = new WrongCat();

    std::cout << "\nCalling makeSound() on WrongAnimal pointer:\n";
    wrongAnimal->makeSound(); // Should print the generic WrongAnimal sound

    std::cout << "\nCalling makeSound() on WrongCat pointer:\n";
    wrongCat->makeSound(); // Should print the WrongAnimal sound instead of WrongCat sound

    delete wrongAnimal;
    delete wrongCat;
	delete minou;
	delete poudel;
	delete animal;

	return 0;
}
