#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
/* 	Animal *ptr = new Animal[10];
	for (int i = 0; i < 5; i++)
	{
		ptr[i] = Dog();
	}
	for (int i = 5; i < 10; i++)
	{
		ptr[i] = Cat();
	}
	for (int i = 0; i < 10; i++)
	{
		ptr[i].makeSound();
	}
	delete [] ptr; */

	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
}
