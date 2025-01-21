#pragma once
#include "AForm.hpp"
#include <string>
#include <iostream>
class Bureaucrat;

class PresidentialPardonForm : public AForm
{

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &that);
	~PresidentialPardonForm();

	int execute(const Bureaucrat &b) const;

private:
	std::string target_;
};
