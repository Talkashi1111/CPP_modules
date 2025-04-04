#include "Account.hpp"
#include <iostream>
#include <vector>
#include <exception>
#include <ctime>


int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;


Account::Account( int initial_deposit)
{
	_nbAccounts++;
	_accountIndex = _nbAccounts - 1;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	 _displayTimestamp();
	 std::cout<< " index:\033[34m"<< _accountIndex << "\033[0m;" <<"amount:\033[34m" << _amount <<"\033[0m;created" <<std::endl;
}
Account::~Account( void )
{
	_nbAccounts--;
	_displayTimestamp();
	std::cout << " index:\033[34m" << _accountIndex << "\033[0m;amount:\033[34m" << _amount << "\033[0m;closed" << std::endl;
}
int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}
void Account::_displayTimestamp( void )
{
	std::time_t currentTime = std::time(0);
	struct tm *timeinfo = std::localtime(&currentTime);
	char buffer_day[80];
	char buffer_time[80];
	//std::cout << "the current time is " ;
	std::strftime(buffer_day, 80, "%Y%m%d", timeinfo);
	std::strftime(buffer_time, 80, "%H%M%S", timeinfo);
	std::cout << '[' <<buffer_day << "_" << buffer_time << "]";


}

int		Account::checkAmount( void ) const
{
	return (_amount);
}
void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << " index:\033[34m" << _accountIndex << "\033[0m;p_amount:\033[34m" << _amount << "\033[0m;deposit\033[34m" << deposit << "\033[0m;";
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "amount:\033[34m" << _amount << "\033[0m;"<< "nb_deposits:\033[34m"<< _nbDeposits <<"\033[0m"<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << " index:\033[34m" << _accountIndex << "\033[0m;p_amount:\033[34m" << _amount << "\033[0m: withdrawals:" ;
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << "\033[34m" << _amount << "\033[0m;nb_withdrawals:\033[34m" << _nbWithdrawals << "\033[0m" << std::endl;
	return (true);
}
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:\033[34m" << _nbAccounts << "\033[0m;total:\033[34m" << _totalAmount <<
		"\033[0m;deposits:\033[34m" << _totalNbDeposits << "\033[0m;withdrawals:\033[34m" <<
			 _totalNbWithdrawals << "\033[0m;" << std::endl;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:\033[34m" << _accountIndex << "\033[0m;amount:\033[34m" << _amount << "\033[0m;deposits:\033[34m" << _nbDeposits << "\033[0m;withdrawals:\033[34m" << _nbWithdrawals << "\033[0m" << std::endl;
}


