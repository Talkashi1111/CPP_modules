#include "AForm.hpp"
#include <string>
#include <iostream>

class Bureaucrat;
class RobotomyRequestForm : public AForm
{
public:
	class RobotomizeFailedException : public std::logic_error{
		public:
			RobotomizeFailedException(const std::string msg);
	};


	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &that);
	~RobotomyRequestForm();

	int execute(const Bureaucrat &b) const;
	void Robotomize() const;
	private:
		std::string target_;
};
