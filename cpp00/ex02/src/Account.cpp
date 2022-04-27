#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

////////////////////////////////////////////////////////////////////////////////
// CONSTRUCTORS / DESTRUCTORS
////////////////////////////////////////////////////////////////////////////////

Account::Account() : _accountIndex(0),
					 _amount(0),
					 _nbDeposits(0),
					 _nbWithdrawals(0)
{
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts),
										_amount(initial_deposit),
										_nbDeposits(0),
										_nbWithdrawals(0)

{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_totalAmount += _amount;
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";created"
			  << std::endl;
	_nbAccounts++;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";closed"
			  << std::endl;
}

void Account::_displayTimestamp()
{
	time_t curr_time = time(NULL);
	tm *t = std::gmtime(&curr_time);
	std::cout << "[" << std::setfill('0')
			  << std::setw(4) << t->tm_year + 1900
			  << std::setw(2) << t->tm_mon
			  << std::setw(2) << t->tm_mday
			  << "_"
			  << std::setw(2) << t->tm_hour
			  << std::setw(2) << t->tm_min
			  << std::setw(2) << t->tm_sec
			  << "] ";
}

////////////////////////////////////////////////////////////////////////////////
// METHODS
////////////////////////////////////////////////////////////////////////////////

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << ";amount:" << _amount;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (_amount - withdrawal < 0)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << _amount;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;

	return true;
}

int Account::checkAmount() const
{
	return _amount;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

////////////////////////////////////////////////////////////////////////////////
// GETTERS / SETTERS
////////////////////////////////////////////////////////////////////////////////

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}

int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}
