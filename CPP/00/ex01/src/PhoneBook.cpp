/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:50:05 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/29 19:11:57 by lgerard          ###   ########.fr       */
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

void	PhoneBook::search(void)
{
	int	i = 0;
	
	if (this->_count == 0)
	{
		std::cout << "There's no contact recorded." << std::endl;
		return ;
	}
	std::cout << "________________________________________" << std::endl;
	std::cout << "|index|first name| last name|  nickname|" << std::endl;
	std::cout << "|     |          |          |          |" << std::endl;

	
	for (i = 0; i < (this->_count); i++)
	{
		
	}
	std::cout << "PhoneBook search called." << std::endl;
	this->_record[i].get_first_name();
	this->_record[i].get_last_name();
	this->_record[i].get_nickname();
	this->_record[i].get_phone_number();
	this->_record[i].get_darkest_secret();
}

void	PhoneBook::_add_record(int n, std::string *tab)
{
	std::cout << "PhoneBook _add_record called with n = " << n << " ." << std::endl;
	this->_record[n].set_first_name(tab[0]);
	this->_record[n].set_last_name(tab[1]);
	this->_record[n].set_nickname(tab[2]);
	this->_record[n].set_phone_number(tab[3]);
	this->_record[n].set_darkest_secret(tab[4]);
	return ;
}

void	PhoneBook::add_request(void)
{
	std::string	tab[5];
	if (this->_count == 0 && this->_older == -1)
	{
		this->_count++;
		this->_older = 1;
		PhoneBook::_add_record(this->_count - 1, tab);
	}
	else if (this->_count < MAX_RECORD)
	{
		this->_count++;
		PhoneBook::_add_record(this->_count - 1, tab);
	}
	else if (this->_count == MAX_RECORD)
	{
		PhoneBook::_add_record(this->_older - 1, tab);
		if (this->_older < MAX_RECORD)
			this->_older++;
		else
			this->_older = 1;
	}
}
