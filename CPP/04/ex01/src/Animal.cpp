/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:18 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/11 23:11:01 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Animal.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Animal::Animal( void )
{
	std::cout << "Animal default constructor called " << std::endl;
	return ;
}

Animal::Animal( std::string id )
 : 	type(id)
{
	std::cout << "Animal named object constructor called for " << id << std::endl;
	return ;
}

Animal::Animal( const Animal & ct)
 :	type( "copy" )
{
	std::cout << "Animal copy constructor called for " << type << std::endl;
	*this = ct;
	return ;
}

Animal::~Animal( void )
{
	std::cout << "Animal destructor called for " << type << std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

Animal&	Animal::operator=(const Animal& ct)
{
	std::cout 	<< "Animal copy assignment operator called for " << this->type
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

void	Animal::makeSound( void ) const
{
	std::cout << "This Animal makes an animal sound : * CACAPHONY *" << std::endl;
	return ;
}

std::string	Animal::getType( void ) const
{
	return (this->type);
}