#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target_(target)
{
	std::cout << "ShrubberyCreationForm constructor for " << this->target_ << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target_(other.target_)
{
	std::cout << "ShrubberyCreationForm copy constructor for " << this->target_ << std::endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &that)
{
	if (this != &that)
	{
		this->target_ = that.target_;
		AForm::operator=(that);
	}
	std::cout << "ShrubberyCreationForm assignation operator for " << this->target_ << std::endl;
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor for " << this->target_ << std::endl;
}

int ShrubberyCreationForm::execute(const Bureaucrat &b) const
{
	AForm::isExecutable(b);
	std::string new_file_name = this->target_ + "_shrubbery";
	std::ifstream askii_tree("askii_tree.txt");
	if (!askii_tree.is_open())
	{
		std::cout << "File askii_tree.txt not found or could not be opened\n";
		return 0;
	}
	std::ofstream new_file(new_file_name.c_str());
	if (!new_file.is_open())
	{
		std::cout << "File " << new_file_name << " could not be created\n";
		return 0;
	}
	std::string line;
	while (std::getline(askii_tree, line))
	{
		new_file << line << std::endl;
	}
	std::cout << "ShrubberyCreationForm " << this->getName() << " executed by " << b.getName() << std::endl;
	return 1;
}
