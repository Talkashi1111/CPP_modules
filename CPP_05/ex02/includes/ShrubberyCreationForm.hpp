#pragma once
#include "AForm.hpp"
#include <fstream>
class BureauCrat;

class ShrubberyCreationForm : public AForm
{
	public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &that);
	~ShrubberyCreationForm();

	int execute(const Bureaucrat &b) const;

	private:
	std::string target_;

};
