/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:49:15 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/29 18:17:26 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
 :
 _first_name(""), 
 _last_name(""),
 _nickname(""),
 _phone_number(""),
 _darkest_secret("")
{
	std::cout << "Contact constructor called." << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called." << std::endl;
}

std::string	Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string	Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string	Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}

void	Contact::set_first_name(std::string str)
{
	this->_first_name = str;
	return ;
}

void	Contact::set_last_name(std::string str)
{
	this->_last_name = str;
	return ;
}

void	Contact::set_nickname(std::string str)
{
	this->_nickname = str;
	return ;
}

void	Contact::set_phone_number(std::string str)
{
	this->_phone_number= str;
	return ;
}

void	Contact::set_darkest_secret(std::string str)
{
	this->_darkest_secret = str;
	return ;
}
