/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:49:15 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/29 13:25:05 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
 :
 _first_name(""), 
 _last_name(""),
 _nick_name(""),
 _phone_number(""),
 _darkest_secret("")
{
	std::cout << "Contact constructor called." << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called." << std::endl;
}