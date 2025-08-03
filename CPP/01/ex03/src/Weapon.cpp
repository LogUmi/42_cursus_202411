/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:59:42 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/03 14:21:03 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string>
#include <iostream>
#include "Weapon.hpp"

Weapon::Weapon( std::string str )
 :
 type(str)
{
	std::cout << type << " is forged." << std::endl;
	return ;
}

Weapon::~Weapon( void )
{
	std::cout << type << " is melted." << std::endl;
	return ;
}

std::string	Weapon::getType( void ) const
{
	return (this->type);
}

void	Weapon::setType( std::string str )
{
	this->type = str;
	return ;
}
