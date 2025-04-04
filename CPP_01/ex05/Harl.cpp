#include "Harl.hpp"
#include <iostream>
Harl::Harl(void)
{
	log_level[DEBUG] = &Harl::debug;
	log_level[INFO] = &Harl::info;
	log_level[WARNING] = &Harl::warning;
	log_level[ERROR] = &Harl::error;
	// std::cout << "default constructor called " << std::endl;
}

void Harl::complain(std::string level)
{
	if (level == "DEBUG")
		(this->*log_level[DEBUG])();
	else if (level == "INFO")
		(this->*log_level[INFO])();
	else if (level == "WARNING")
		(this->*log_level[WARNING])();
	else if (level == "ERROR")
		(this->*log_level[ERROR])();
	else
		std::cout << "Invalid log level" << std::endl;
}

Harl::~Harl(void)
{
	// std::cout << "destructor called " << std::endl;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put "
				 "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for"
				 "years whereas you started working here since last month."
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
