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

	typedef void (Harl::*ptm)();
	ptm log_level[4];
};

