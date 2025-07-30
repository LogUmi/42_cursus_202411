/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:50:05 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/30 14:19:50 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "main.hpp"

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
	int i = 0;

	if (this->_count == 0)
	{
		std::cout << "[ERROR] there's no contact recorded." << std::endl;
		return;
	}
	std::cout << "________________________________________" << std::endl;
	std::cout << "|index|first name| last name|  nickname|" << std::endl;
	for (i = 1; i <= (this->_count); i++)
	{
		std::cout << "|–––––|––––––––––|––––––––––|––––––––––|" << std::endl;
		std::cout << "|  " << i << "  |";
		std::cout << this->_record[i].get_first_name(0) << "|";
		std::cout << this->_record[i].get_last_name(0) << "|";
		std::cout << this->_record[i].get_first_name(0) << "|" << std::endl;
	}
	std::cout << "|_____|__________|__________|__________|" << std::endl;
	while (true)
	{
		if (get_int(&i, "[INPUT] Please type the index number to show : ") == 0)
		{
			if (i < 1 || i > (this->_count))
			{
				if (this->_count == 1)
					std::cout << "[ERROR] No such an index number recorded ... try only ";
				else
					std::cout << "[ERROR] No such an index number recorded ... try 1 up to ";
				std::cout << (this->_count) << "." << std::endl;
			}
			else
				break;
		}
		else
		{
			std::cout << "[ERROR] Command SEARCH aborted" << std::endl;
			return ;
		}
	}
	std::cout << "[SUCCES] Index " << i << " recorded data:" << std::endl;
	std::cout << "    first name: " << this->_record[i - 1].get_first_name(1) << std::endl;
	std::cout << "     last name: " << this->_record[i - 1].get_last_name(1) << std::endl;
	std::cout << "      nickname: " << this->_record[i - 1].get_nickname(1) << std::endl;
	std::cout << "  phone number: " << this->_record[i - 1].get_phone_number(1) << std::endl;
	std::cout << "darkest secret: " << this->_record[i - 1].get_darkest_secret(1) << std::endl;
	std::cout << "[SUCCES] command SEARCH done" << std::endl;
	return ;
}

void PhoneBook::_add_record(int n, std::string *tab)
{
	std::cout << "PhoneBook _add_record called with n = " << n << " ." << std::endl;
	this->_record[n].set_first_name(tab[0]);
	this->_record[n].set_last_name(tab[1]);
	this->_record[n].set_nickname(tab[2]);
	this->_record[n].set_phone_number(tab[3]);
	this->_record[n].set_darkest_secret(tab[4]);
	return;
}

void PhoneBook::add_request(void)
{
	std::string tab[5];
	
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
	std::cout << "[SUCCES] command ADD done." << std::endl;
	return ;
}
