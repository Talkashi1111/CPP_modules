#include "PhoneBook.hpp"
#include <iterator>

Contact::Contact() : first_name_(""), last_name_(""), nickname_(""), phonenumber_(""), darkest_secret_("") {}

Contact::Contact(const std::string &first_name,
				 const std::string &last_name,
				 const std::string &nickname,
				 const std::string &phone_number,
				 const std::string &darkest_secret) : first_name_(first_name),
													  last_name_(last_name),
													  nickname_(nickname),
													  phonenumber_(phone_number),
													  darkest_secret_(darkest_secret) {}

std::string Contact::GetShort(std::string str)
{
	if (str.length() > 10)
	{
		str.resize(10);
		str[9] = '.';
	}
	return str;
}

void Contact::PrintShort(int i)
{
	if (this->first_name_.empty())
		return;
	std::cout << std::setw(10) << i << "|";
	std::cout << std::setw(10) << GetShort(this->first_name_) << "|";
	std::cout << std::setw(10) << GetShort(this->last_name_) << "|";
	std::cout << std::setw(10) << GetShort(this->nickname_) << "|" << std::endl;
}

void Contact::PrintFull()
{
	std::cout << "First name: " << this->first_name_ << std::endl;
	std::cout << "Last name: " << this->last_name_ << std::endl;
	std::cout << "Nickname: " << this->nickname_ << std::endl;
	std::cout << "Phone number: " << this->phonenumber_ << std::endl;
	std::cout << "Darkest secret: " << this->darkest_secret_ << std::endl;
}

Contact::~Contact() {}
