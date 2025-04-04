#pragma once
#include <iostream>

enum LogLevel {
	DEBUG,
	INFO,
	WARNING,
	ERROR
};


class Harl {
	public:
	Harl( void );
	~Harl( void );
	void complain ( std::string level );
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
	int get_log_level( std::string level );
	typedef void (Harl::*ptm)(void);// typedef to pointer to member functions
	ptm log_level[4];// this array should be of the same signature for each member function (meaning all having void as return type and void as parameters)
};

