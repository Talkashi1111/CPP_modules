#include "PhoneBook.hpp"

int main()
{
	PhoneBook my_phonebook;
	std::string command;
	std::cout << "\t\tWELCOME TO MY PHONEBOOK\n"
			  << "\t\tCommands: ADD, SEARCH, EXIT" << std::endl;
	std::cout << "Enter a command: ";
	while (std::getline(std::cin, command))
	{
		if (command == "EXIT")
			break;
		else if (command == "ADD")
			my_phonebook.AddContact();
		else if (command == "SEARCH")
			my_phonebook.SearchContact();

		std::cout << "Enter a command: ";
	}
	return 0;
}
