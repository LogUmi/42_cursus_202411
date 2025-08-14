/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:12:37 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/14 12:52:55 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Ice.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Ice::Ice( void )
:	AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
	return ;
}

Ice::Ice(Ice const & am)
 :	AMateria(am.type)
{
	std::cout 	<< "Ice copy constructor called for " 
				<< this->type << std::endl;
	return ;
}

Ice::~Ice( void )
{
	std::cout 	<< "Ice destructor called for " 
				<< this->type << std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

Ice &	Ice::operator=(Ice const & am)
{
	std::cout 	<< "Ice assignation overload called for " 
				<< this->type << " = " << am.type << std::endl;
	if (this != &am)
		this->type = am.type;
	return (*this);
}

// ****************************************************************************
// clone function
// ****************************************************************************

Ice* 	Ice::clone( void ) const
{
	return (new Ice(*this));
}

// ****************************************************************************
// overload of << ostream operator
// ****************************************************************************

std::ostream &	operator<<(std::ostream& os, const Ice& am)
{
	os << "Ice type " << am.getType();
	return (os);
}

// ****************************************************************************
// member functions
// ****************************************************************************
