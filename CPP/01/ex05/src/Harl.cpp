/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:18 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/05 21:57:58 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

Harl::Harl( void )
{
	Harl::table[0].name = "DEBUG";
	Harl::table[0].function = &Harl::debug;
	Harl::table[1].name = "INFO";
	Harl::table[1].function = &Harl::info;
	Harl::table[2].name = "WARNING";
	Harl::table[2].function = &Harl::warning;
	Harl::table[3].name = "ERROR";
	Harl::table[3].function = &Harl::error;
	std::cout << "Harl 2.0 booted and is ready." << std::endl;
	return ;
}
Harl::~Harl( void )
{
	std::cout << "Harl 2.0 is shutting off." << std::endl;
	return ;
}

void Harl::debug( void )
{
	std::cout 	<< "[ DEBUG ]" << std::endl
				<< "I love having extra bacon for my "
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger."
				<< std::endl << "I really do!" << std::endl << std::endl;
	return ;
}

void Harl::info( void )
{
	std::cout 	<< "[ INFO ]" << std::endl
				<< "I cannot believe adding extra bacon costs more money." << std::endl
				<< "You didn’t put enough bacon in my burger! If you did, "
				<< "I wouldn’t be asking for more!" << std::endl << std::endl;
	return ;
}

void Harl::warning( void )
{
	std::cout 	<< "[ WARNING ]" << std::endl
				<< "I think I deserve to have some extra bacon for free." << std::endl
				<< "I’ve been coming for years, whereas you started working "
				<< "here just last month." << std::endl << std::endl;
	return ;
}

void Harl::error( void )
{
	std::cout 	<< "[ ERROR ]" << std::endl
				<< "This is unacceptable! I want to speak to the manager now."
				<< std::endl << std::endl;
	return ;
}

void	Harl::complain( std::string level )
{
	for (int i = 0; i < 4; i++)
	{
		if (level == this->table[i].name)
		{
			(this->*table[i].function)();
			return ;
		}
	}
	std::cout 	<< "[ Probably complaining about insignificant problems ]"
				<< std::endl;
	return ;
}