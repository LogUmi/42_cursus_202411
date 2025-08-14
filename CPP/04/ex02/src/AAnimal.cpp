/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:18 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/13 22:15:10 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AAnimal.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

AAnimal::AAnimal( void )
{
	std::cout << "AAnimal default constructor called " << std::endl;
	return ;
}

AAnimal::AAnimal( std::string id )
 : 	type(id)
{
	std::cout << "AAnimal named object constructor called for " << id << std::endl;
	return ;
}

AAnimal::AAnimal( const AAnimal & ct)
 :	type( "copy" )
{
	std::cout << "AAnimal copy constructor called for " << type << std::endl;
	*this = ct;
	return ;
}

AAnimal::~AAnimal( void )
{
	std::cout << "AAnimal destructor called for " << type << std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

AAnimal&	AAnimal::operator=(const AAnimal& ct)
{
	std::cout 	<< "AAnimal copy assignment operator called for " << this->type
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

void	AAnimal::makeSound( void ) const
{
	std::cout << "This AAnimal makes an AAnimal sound : * CACAPHONY *" << std::endl;
	return ;
}

std::string	AAnimal::getType( void ) const
{
	return (this->type);
}