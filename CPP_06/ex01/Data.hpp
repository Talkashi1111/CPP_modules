#pragma once
#include <string>

class Data
{
	public:
	Data(int phoneNumber, std::string name);
	Data(const Data& other);
	Data& operator=(const Data& that);
	~Data();

	int getPhoneNumber() const;
	std::string getName() const;

	private:
	int phoneNumber;
	std::string name;
};
