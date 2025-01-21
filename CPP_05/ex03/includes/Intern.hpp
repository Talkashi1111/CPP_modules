#pragma once
#include <string>
#include <iostream>


class AForm;
class Bureaucrat;


class Intern{
public:
	Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	~Intern();

	AForm *makeForm(std::string const &name, std::string const &target);
	class UnknownFormat : public std::invalid_argument{
		public:
			UnknownFormat(const std::string msg);
	};

private:
	typedef AForm* (*Prototypes)(std::string const &target);//typedef for a pointer to a function that takes a string as an argument and returns a pointer to an AForm

};
