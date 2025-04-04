#include <limits>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	next_free_index_ = 0;
	contacts_cnt_ = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::AddContact()
{
	std::string first_name, last_name, nickname, phonenumber, darkest_secret;

	std::cout << "Enter first name: ";
	if (!std::getline(std::cin, first_name))
		return;
	if (first_name.empty())
	{
		std::cout << "First name cannot be empty" << std::endl;
		return;
	}

	std::cout << "Enter last name: ";
	if (!std::getline(std::cin, last_name))
		return;
	if (last_name.empty())
	{
		std::cout << "Last name cannot be empty" << std::endl;
		return;
	}

	std::cout << "Enter nickname: ";
	if (!std::getline(std::cin, nickname))
		return;
	if (nickname.empty())
	{
		std::cout << "Nickname cannot be empty" << std::endl;
		return;
	}

	std::cout << "Enter phone number: ";
	if (!std::getline(std::cin, phonenumber))
		return;
	if (phonenumber.empty())
	{
		std::cout << "Phone number cannot be empty" << std::endl;
		return;
	}

	std::cout << "Enter darkest secret: ";
	if (!std::getline(std::cin, darkest_secret))
		return;
	if (darkest_secret.empty())
	{
		std::cout << "Darkest secret cannot be empty" << std::endl;
		return;
	}

	Contact contact(first_name, last_name, nickname, phonenumber, darkest_secret);
	this->contacts_[next_free_index_] = contact;
	next_free_index_ = (next_free_index_ + 1) % MAX_CONTACTS;
	if (contacts_cnt_ < MAX_CONTACTS)
		contacts_cnt_++;
}

void PhoneBook::SearchContact()
{
	int index;
	if (this->contacts_cnt_ == 0)
	{
		std::cout << "No contacts available" << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << '|' << std::endl;
	for (int i = 0; i < this->contacts_cnt_; i++)
		contacts_[i].PrintShort(i + 1);
	std::cout << "Enter index: ";
	if (!(std::cin >> index)) // Check if input is invalid (non-integer)
	{
		std::cin.clear();													// Clear the error state of std::cin
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore any remaining input
		std::cout << "Invalid input" << std::endl;
		return;
	}
	std::cin.clear();													// Clear the error state of std::cin
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore any remaining input
	if (index < 1 || index > this->contacts_cnt_)
	{
		std::cout << "Unavailable contact" << std::endl;
		return;
	}
	index--;
	std::cout << "Contact details" << std::endl;
	contacts_[index].PrintFull();
}
