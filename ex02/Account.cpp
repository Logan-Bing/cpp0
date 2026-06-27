#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

Account::Account(int initial_deposit)
{
	
}

void	Account::_displayTimestamp()
{
	char c = std::cout.fill();
	std::time_t t = std::time(nullptr);
	std::tm *tm = std::localtime(&t);
	std::cout << '[' << tm->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_mon + 1 << std::setw(2) << tm->tm_mday;
	std::cout << '_' << tm->tm_hour << tm->tm_min << tm->tm_sec << ']';
	std::cout << std::setfill(c);
}

void	Account::makeDeposit(int deposit)
{

}

bool	Account::makeWithdrawal(int withdrawal)
{

}

int		Account::checkAmount() const
{
	return (this->_amount);
}

void	Account::displayStatus() const
{

}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}
