/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:18 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/11 23:10:42 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

WrongAnimal::WrongAnimal( void )
{
	std::cout << "WrongAnimal default constructor called " << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( std::string id )
 : 	type(id)
{
	std::cout << "WrongAnimal named object constructor called for " << id << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal & ct)
 :	type( "copy" )
{
	std::cout << "WrongAnimal copy constructor called for " << type << std::endl;
	*this = ct;
	return ;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal destructor called for " << type << std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& ct)
{
	std::cout 	<< "WrongAnimal copy assignment operator called for " << this->type
				<< " = " << ct.type <<std::endl;
	if (this != &ct)
	{
		this->type = ct.type;
	}
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "This WrongAnimal makes an WrongAnimal sound: * CACAPHONY *" << std::endl;
	return ;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}