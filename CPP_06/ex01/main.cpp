#include "Serializer.hpp"
#include <iostream>
int main()
{
	Data originData = Data(1234567890, "John Doe");
	Data *ptr = &originData;
	uintptr_t raw = Serializer::serialize(ptr);
	Data *newData = Serializer::deserialize(raw);

	if (newData == ptr)
	{
		std::cout<<"Data objects are the same"<<std::endl;
	}
	else
	{
		std::cout<<"Data objects are different"<<std::endl;
	}
	return 0;
}
