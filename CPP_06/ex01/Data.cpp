#include "Data.hpp"
#include <iostream>

Data::Data(int phoneNumber, std::string name) : phoneNumber(phoneNumber), name(name)
{
	std::cout<<"Data constructor called for " << this->name <<std::endl;
}

Data::Data(const Data& other) : phoneNumber(other.phoneNumber), name(other.name)
{
	std::cout<<"Data copy constructor called"<<std::endl;
}

Data& Data::operator=(const Data& that)
{
	if (this != &that)
	{
		this->phoneNumber = that.phoneNumber;
		this->name = that.name;
	}
	std::cout<<"Data assignment operator called"<<std::endl;
	return *this;
}

Data::~Data()
{
	std::cout<<"Data destructor called"<<std::endl;
}

int Data::getPhoneNumber() const
{
	return this->phoneNumber;
}

std::string Data::getName() const
{
	return this->name;
}
