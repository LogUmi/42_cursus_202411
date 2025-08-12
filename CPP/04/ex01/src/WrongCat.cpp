/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:26:37 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/11 23:08:20 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "WrongCat.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

WrongCat::WrongCat( void )
 :	WrongAnimal( "WrongCat" ),
 	name( "Weirdo" )
{
	std::cout 	<< "WrongCat default constructor called for " 
				<< this->name << std::endl;
	return ;
}

WrongCat::WrongCat( std::string id ) 
: 	WrongAnimal( "WrongCat" ),
	name( id )
{
	std::cout << "WrongCat named object constructor called for " << name << std::endl;
	return ;
}

WrongCat::WrongCat( const WrongCat & ct)
 :	WrongAnimal( "WrongCat" ),
	name( "copy" )
{
	std::cout << "WrongCat copy constructor called for " << name << std::endl;
	*this = ct;
	return ;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat destructor called for " << name << std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

WrongCat&	WrongCat::operator=(const WrongCat& ct)
{
	std::cout 	<< "WrongCat copy assignment operator called for " << this->name
				<< " = " << ct.name << std::endl;
	if (this != &ct)
	{
		this->name = ct.name;
		WrongAnimal::type = ct.getType();
	}
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

void	WrongCat::makeSound( void ) const
{
	std::cout << "This WrongCat makes a WrongCat sound: MEEEEOOOOOOW " << std::endl;
}

std::string	WrongCat::getName( void ) const
{
	return (this->name);
}