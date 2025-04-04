#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#define MAX_CONTACTS 8

#include <iomanip>
#include <string>
#include <iostream>
#include <exception>

class Contact
{
public:
	Contact();
	Contact(const std::string &first_name, const std::string &last_name, const std::string &nickname, const std::string &phonenumber, const std::string &darkest_secret);
	~Contact();

	void PrintShort(int i);
	void PrintFull();

private:
	std::string GetShort(std::string str);

	// data members
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phonenumber_;
	std::string darkest_secret_;
};

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	void AddContact();
	void SearchContact();
	void Exit();

private:
	// data members
	Contact contacts_[MAX_CONTACTS];
	int next_free_index_;
	int contacts_cnt_;
};

#endif
