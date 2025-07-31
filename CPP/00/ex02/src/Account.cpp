/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:37:17 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/31 20:20:43 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) 
: 	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{	
	_totalAmount += _amount;
	_nbAccounts++;
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex << ";amount:" << _amount << ";created"
				<< std::endl;
}
Account::~Account( void )
{
	_displayTimestamp();
	std::cout 	<< "index:" << _accountIndex << ";amount:" << _amount << ";closed"
				<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t		stamp;
	struct tm*	ts;
	
	time( &stamp );
	ts = localtime(&stamp);
	std::cout 	<< "[" << ts->tm_year + 1900 << std::setfill('0') << std::setw(2) 
				<< ts->tm_mon << std::setw(2) << ts->tm_mday << "_" << std::setw(2)
				<< ts->tm_hour << std::setw(2) << ts->tm_min << std::setw(2)
				<< ts->tm_sec << "] ";
	return ;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::makeDeposit( int deposit )
{
	if (deposit > 0)
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount;
		this->_amount += deposit;
		this->_totalAmount += deposit;
		this->_nbDeposits++;
		_totalNbDeposits++;
		std::cout 	<< ";deposit:" << deposit << ";amount:" << this->_amount
					<< ";nb_deposits:" << this->_nbDeposits << std::endl;
	}	
}
bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > 0)
	{
		_displayTimestamp();
		std::cout 	<< "index:" << this->_accountIndex << ";p_amount:" << this->_amount 
					<< ";withdrawal:";
		if (this->_amount >= withdrawal)
		{
			this->_amount -= withdrawal;
			this->_totalAmount -= withdrawal;
			this->_nbWithdrawals++;
			_totalNbWithdrawals++;
			std::cout 	<< withdrawal << ";amount:" << this->_amount
					<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		}
		else
			std::cout 	<< "refused" << std::endl;
	}
	return (false);	
}
int		Account::checkAmount( void ) const
{
	return (this->_amount);	
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout 	<< "index:" << this->_accountIndex << ";amount:" << this->_amount 
				<< ";deposits:" << this->_nbDeposits << ";withdrawals:" 
				<< this->_nbWithdrawals << std::endl;
	return ;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout 	<< "accounts:" << _nbAccounts << ";total:" << _totalAmount 
				<< ";deposits:" << _totalNbDeposits << ";withdrawals:" 
				<< _totalNbWithdrawals << std::endl;
	return ;
}
