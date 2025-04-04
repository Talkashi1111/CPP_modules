#include "Harl.hpp"
#include <iostream>
Harl::Harl( void )
{
	log_level[DEBUG] = &Harl::debug;
	log_level[INFO] = &Harl::info;
	log_level[WARNING] = &Harl::warning;
	log_level[ERROR] = &Harl::error;;
}

int Harl::get_log_level( std::string level )
{
	if (level == "DEBUG")
		return DEBUG;
	else if (level == "INFO")
		return INFO;
	else if (level == "WARNING")
		return WARNING;
	else if (level == "ERROR")
		return ERROR;
	else
		return -1;
}

void Harl::complain( std::string level )
{
	int level_index = get_log_level(level);
	switch (level_index)
	{
		case DEBUG :
		{
			(this->*log_level[DEBUG])();
			(this->*log_level[INFO])();
			(this->*log_level[WARNING])();
			(this->*log_level[ERROR])();
			break;
		}
		case INFO :
		{
			(this->*log_level[INFO])();
			(this->*log_level[WARNING])();
			(this->*log_level[ERROR])();
			break;
		}
		case WARNING :
		{
			(this->*log_level[WARNING])();
			(this->*log_level[ERROR])();
			break;
		}
		case ERROR :
		{
			(this->*log_level[ERROR])();
			break;

		}
		default:
		{
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		}
	}
}

Harl::~Harl (void ) {}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put "
	"enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for"
"years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n"<< std::endl;
}
