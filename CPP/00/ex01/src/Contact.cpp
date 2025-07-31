/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:49:15 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/31 12:44:56 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact( void )
 :
 _first_name(""), 
 _last_name(""),
 _nickname(""),
 _phone_number(""),
 _darkest_secret("")
{
	//std::cout << "Contact constructor called." << std::endl;
}

Contact::~Contact( void )
{
	//std::cout << "Contact destructor called." << std::endl;
}

std::string	Contact::_string_way( std::string str, int way ) const
{
	int	i = str.size();

	if (way != 0)
		return (str);
	if (i > 10)
		return (str.substr(0, 9) + "."); 
	else if (i < 10)
		return (std::string(10 - str.size(), ' ') + str);
	return (str);
}

std::string	Contact::get_first_name( int way ) const
{
	return (Contact::_string_way(this->_first_name, way));
}

std::string	Contact::get_last_name( int way ) const
{
	return (Contact::_string_way(_last_name, way));
}

std::string	Contact::get_nickname( int way ) const
{
	return (Contact::_string_way(this->_nickname, way));
}

std::string	Contact::get_phone_number( int way ) const
{
	return (Contact::_string_way(this->_phone_number, way));
}

std::string	Contact::get_darkest_secret( int way ) const
{
	return (Contact::_string_way(this->_darkest_secret, way));
}

void	Contact::set_first_name( std::string str )
{
	this->_first_name = str;
	return ;
}

void	Contact::set_last_name( std::string str )
{
	this->_last_name = str;
	return ;
}

void	Contact::set_nickname( std::string str )
{
	this->_nickname = str;
	return ;
}

void	Contact::set_phone_number( std::string str )
{
	this->_phone_number= str;
	return ;
}

void	Contact::set_darkest_secret( std::string str )
{
	this->_darkest_secret = str;
	return ;
}
