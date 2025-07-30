/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:50:05 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/30 21:02:18 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"
#include "main.hpp"

PhoneBook::PhoneBook(void) : _older(-1), _count(0)
{
	//std::cout << "PhoneBook constructor called." << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	//std::cout << "PhoneBook destructor called." << std::endl;
}

void PhoneBook::search(void) const
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
		std::cout << this->_record[i - 1].get_first_name(0) << "|";
		std::cout << this->_record[i - 1].get_last_name(0) << "|";
		std::cout << this->_record[i - 1].get_nickname(0) << "|" << std::endl;
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
	this->_record[n].set_first_name(tab[0]);
	this->_record[n].set_last_name(tab[1]);
	this->_record[n].set_nickname(tab[2]);
	this->_record[n].set_phone_number(tab[3]);
	this->_record[n].set_darkest_secret(tab[4]);
	return;
}

int	PhoneBook::_get_record(std::string *tab) const
{
	std::string	prompt0 = "[INPUT] Please type ";
	std::string	prompt1 = int_to_string(MAX_CHAR_NAMES);
	std::string	prompt2 = " alphabetics (including ' ', '\'' and '-') as ";
	std::string prompt3 = "first name: ";
	
	while (true)
	{
		if (get_str(tab[0], prompt0 + prompt1 + prompt2 + prompt3) == 0)
		{
			if (is_name(tab[0]) != 0)
				std::cout << "[ERROR] Wrong character(s) in the string." << std::endl;
			else if (tab[0].size() > MAX_CHAR_NAMES)
				std::cout << "[ERROR] More than " << MAX_CHAR_NAMES	<< " characters." << std::endl;
			else if (tab[0].empty())
				std::cout << "[ERROR] No NULL allowed." << std::endl;
			else
				break ;
		}
		else
			return (1);
	}
	prompt3 = "last name: ";
	while (true)
	{
		if (get_str(tab[1], prompt0 + prompt1 + prompt2 + prompt3) == 0)
		{
			if (is_name(tab[1]) != 0)
				std::cout << "[ERROR] Wrong character(s) in the string." << std::endl;
			else if (tab[1].size() > MAX_CHAR_NAMES)
				std::cout << "[ERROR] More than " << MAX_CHAR_NAMES	<< " characters." << std::endl;
			else if (tab[1].empty())
				std::cout << "[ERROR] No NULL allowed." << std::endl;
			else
				break ;
		}
		else
			return (1);
	}
	prompt2 = " printables as ";
	prompt3 = "nickname: ";
	while (true)
	{
		if (get_str(tab[2], prompt0 + prompt1 + prompt2 + prompt3) == 0)
		{
			if (is_printable(tab[2]) != 0)
				std::cout << "[ERROR] Wrong character(s) in the string." << std::endl;
			else if (tab[2].size() > MAX_CHAR_NAMES)
				std::cout << "[ERROR] More than " << MAX_CHAR_NAMES	<< " characters." << std::endl;
			else if (tab[2].empty())
				std::cout << "[ERROR] No NULL allowed." << std::endl;
			else
				break ;
		}
		else
			return (1);
	}
	prompt1 = int_to_string(MAX_PHONE_NBR);
	prompt2 = " digitals as ";
	prompt3 = "phone number: ";
	while (true)
	{
		if (get_str(tab[3], prompt0 + prompt1 + prompt2 + prompt3) == 0)
		{
			if (is_digit(tab[3]) != 0)
				std::cout << "[ERROR] Wrong character(s) in the string." << std::endl;
			else if (tab[3].size() > MAX_PHONE_NBR)
				std::cout << "[ERROR] More than " << MAX_PHONE_NBR	<< " characters." << std::endl;
			else if (tab[3].empty())
				std::cout << "[ERROR] No NULL allowed." << std::endl;
			else
				break ;
		}
		else
			return (1);
	}
	prompt1 = int_to_string(MAX_CHAR_SECRET);
	prompt2 = " printables as ";
	prompt3 = "darkest secret: ";
	while (true)
	{
		if (get_str(tab[4], prompt0 + prompt1 + prompt2 + prompt3) == 0)
		{
			if (is_printable(tab[4]) != 0)
				std::cout << "[ERROR] Wrong character(s) in the string. " << std::endl;
			else if (tab[4].size() > MAX_CHAR_SECRET)
				std::cout << "[ERROR] More than " << MAX_CHAR_SECRET << " characters." << std::endl;
			else if (tab[4].empty())
				std::cout << "[ERROR] No NULL allowed." << std::endl;
				else
				break ;
		}
		else
			return (1);
	}

	return (0);
}

void PhoneBook::add_request(void)
{
	std::string tab[5];
	
	if (PhoneBook::_get_record(tab) == 1)
	{
		std::cout << "[ERROR] Command ADD aborted - No index recorded" << std::endl;
		return ;
	}
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
