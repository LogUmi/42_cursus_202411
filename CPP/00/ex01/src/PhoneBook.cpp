/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:50:05 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/29 13:45:07 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _older(-1), _count(0)
{
	std::cout << "PhoneBook constructor called." << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called." << std::endl;
}

void PhoneBook::search(void)
{
	std::cout << "PhoneBook search called." << std::endl;
}

void	PhoneBook::_add_record(int n)
{
	std::cout << "PhoneBook _add_record called with n = " << n << " ." << std::endl;
}

void	PhoneBook::add_request(void)
{
	if (this->_count == 0 && this->_older == -1)
	{
		this->_count++;
		this->_older = 1;
		PhoneBook::_add_record(this->_count - 1);
	}
	else if (this->_count < MAX_RECORD)
	{
		this->_count++;
		PhoneBook::_add_record(this->_count - 1);
	}
	else if (this->_count == MAX_RECORD)
	{
		PhoneBook::_add_record(this->_older - 1);
		if (this->_older < MAX_RECORD)
			this->_older++;
		else
			this->_older = 1;
	}
}