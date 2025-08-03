/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 13:18:30 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/03 13:39:28 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "HumanA.hpp"

HumanA::HumanA( std::string id, Weapon& item ) : name(id), weapon(item)
{
	std::cout 	<< this->name << " is born with a(n) " << this->weapon.getType() 
				<< " in his hands." << std::endl;
	return ;
}

HumanA::~HumanA( void )
{
	std::cout 	<< this->name << " died." << std::endl;
	return ;
}

void HumanA::attack( void ) const
{
	std::cout 	<< this->name << " attacks with their " << this->weapon.getType()
				<< std::endl;
	return ;
}
