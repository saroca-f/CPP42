/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:06:00 by saroca-f          #+#    #+#             */
/*   Updated: 2024/08/09 16:35:40 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int _accountIndex = 0;
int _amount = 0;
int _nbDeposits = 0;
int _nbWithdrawals = 0;

using namespace std;

Account::Account(int initial_deposit)
{
    this->_amount = initial_deposit;
    this->_accountIndex = Account::_nbAccounts;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    Account::_displayTimestamp();
    cout << "index:" << this->_accountIndex << ";";
    cout << "amount:" << this->_amount << ";";
    cout << "created" << endl;
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    _nbAccounts--;
    cout << "index:" << this->_accountIndex << ";";
    cout << "amount:" << this->_amount << ";";
    _totalAmount -= this->_amount;
    this->_amount = 0;
    this->_nbWithdrawals++;
    cout << "closed" << endl;
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

void	Account::_displayTimestamp( void )
{
	time_t t_now;
	tm*	t_info;
	char		t_formated[20];

	time(&t_now);
	t_info = localtime(&t_now);
	strftime(t_formated, sizeof(t_formated), "[%Y%m%d_%H%M%S]", t_info);
	cout << t_formated << " ";
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    cout << "index:" << this->_accountIndex << ";";
    cout << "amount:" << this->_amount << ";";
    cout << "deposits:" << this->_nbDeposits << ";";
    cout << "withdrawals:" << this->_nbWithdrawals << endl;
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    cout << "accounts:" << Account::_nbAccounts << ";";
    cout << "total:" << Account::_totalAmount << ";";
    cout << "deposits:" << Account::_totalNbDeposits << ";";
    cout << "withdrawals:" << Account::_totalNbWithdrawals << endl;
}

void	Account::makeDeposit( int deposit )
{
    Account::_displayTimestamp();
    cout << "index:" << this->_accountIndex << ";";
    cout << "p_amount:" << this->_amount << ";";

    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;

    cout << "deposit:" << deposit << ";";
    cout << "amount:" << this->_amount << ";";
    cout << "nb_deposits:" << this->_nbDeposits << endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_displayTimestamp();
    cout << "index:" << this->_accountIndex << ";";
    cout << "p_amount:" << this->_amount << ";";
    cout << "withdrawal:";

    if(withdrawal > this->_amount)
    {
        cout << "refused" << endl;
        return (false);
    }
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;

    cout << withdrawal << ";" << "amount:" << this->_amount << ";";
    cout << "nb_withdrawals:" << this->_nbWithdrawals << endl;
    return (true);
}
