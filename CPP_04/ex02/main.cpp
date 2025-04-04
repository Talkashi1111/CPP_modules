#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	AAnimal *dog;
	Dog my_dog;
	dog = &my_dog;
	dog->makeSound();
	//AAnimal cat; not possible because AAnimal is an abstract class
	}
