/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:11:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/14 12:52:42 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>
#include "Cure.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Cure::Cure( void )
:	AMateria("Cure")
{
	std::cout << "Cure default constructor called" << std::endl;
	return ;
}

Cure::Cure(Cure const & am)
 :	AMateria(am.type)
{
	std::cout 	<< "Cure copy constructor called for " 
				<< this->type << std::endl;
	return ;
}

Cure::~Cure( void )
{
	std::cout 	<< "Cure destructor called for " 
				<< this->type << std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

Cure &	Cure::operator=(Cure const & am)
{
	std::cout 	<< "Cure assignation overload called for " 
				<< this->type << " = " << am.type << std::endl;
	if (this != &am)
		this->type = am.type;
	return (*this);
}

// ****************************************************************************
// clone function
// ****************************************************************************

Cure* 	Cure::clone( void ) const
{
	return (new Cure(*this));
}

// ****************************************************************************
// overload of << ostream operator
// ****************************************************************************

std::ostream &	operator<<(std::ostream& os, const Cure& am)
{
	os << "Cure type " << am.getType();
	return (os);
}

// ****************************************************************************
// member functions
// ****************************************************************************
