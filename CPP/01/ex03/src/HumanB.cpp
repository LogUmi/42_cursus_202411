/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 13:18:30 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/03 14:17:42 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanB.hpp"

HumanB::HumanB( std::string id ) : name(id), weapon(NULL)
{
	std::cout 	<< this->name << " is born empty handed." << std::endl;
	return ;
}

HumanB::~HumanB( void )
{
	std::cout 	<< this->name << " died." << std::endl;
	return ;
}

void HumanB::attack( void ) const
{
	std::cout 	<< this->name << " attacks with their "
				<< this->weapon->getType() << std::endl;
	return ;
}

void HumanB::setWeapon( Weapon& item )
{
	this->weapon = &item;
	std::cout 	<< this->name << " take a(n) "
				<< this->weapon->getType() << std::endl;
	return ;
}
