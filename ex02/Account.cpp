#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_totalAmount += initial_deposit;

	this->_amount = initial_deposit;
	this->_accountIndex = _nbAccounts++;
	_displayTimestamp();
	std::cout 
			<< " index:" << this->_accountIndex << ";"
			<< "amount:" << this->checkAmount() << ";"
			<< "created" << '\n';
}

Account::~Account()
{
	_displayTimestamp();
	std::cout 
			<< " index:" << this->_accountIndex << ";"
			<< "amount:" << this->checkAmount() << ";"
			<< "closed" << '\n';
}

void	Account::_displayTimestamp()
{
	char c = std::cout.fill();
	std::time_t t = std::time(NULL);
	std::tm *tm = std::localtime(&t);
	std::cout << '[' << tm->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0');
	std::cout << tm->tm_mon + 1 << std::setw(2) << tm->tm_mday;
	std::cout << '_' << tm->tm_hour << tm->tm_min << tm->tm_sec << ']';
	std::cout << std::setfill(c);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout 
		<< " accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << '\n';
}

void	Account::makeDeposit(int deposit)
{
	_totalAmount += deposit;
	_totalNbDeposits++;

	int p_amount(this->_amount);
	this->_amount += deposit;
	this->_nbDeposits++;
	_displayTimestamp();
	std::cout 
			<< " index:" << this->_accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "deposit:" << deposit << ";"
			<< "amount:" << this->checkAmount() << ";"
			<< "nb_deposits:" << this->_nbDeposits << '\n';
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int p_amount(this->_amount);

	_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std::cout 
			<< " index:" << this->_accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "withdrawal:" << "refused" << '\n';
		return (false);
	}

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	std::cout 
			<< " index:" << this->_accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "withdrawal:" << withdrawal << ";"
			<< "amount:" << this->checkAmount() << ";"
			<< "nb_withdrawals:" << this->_nbWithdrawals << '\n';
	return (true);
}

int		Account::checkAmount() const
{
	return (this->_amount);
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout 
			<< " index:" << this->_accountIndex << ";"
			<< "amount:" << this->checkAmount() << ";"
			<< "deposits:" << this->_nbDeposits << ";"
			<< "withdrawals:" << this->_nbWithdrawals << '\n';
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

