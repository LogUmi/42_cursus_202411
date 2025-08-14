/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:01:38 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/14 13:04:02 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AMateria.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

AMateria::AMateria( void )
{
	std::cout << "AMateria default constructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const & type)
 :	type (type)
{
	std::cout 	<< "AMateria typed constructor called for " 
				<< this->type << std::endl;
	return ;
}

AMateria::AMateria(AMateria const & am)
 :	type (am.type)
{
	std::cout 	<< "AMateria copy constructor called for " 
				<< this->type << std::endl;
	return ;
}

AMateria::~AMateria( void )
{
	std::cout 	<< "AMateria destructor called for " 
				<< this->type << std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

AMateria &	AMateria::operator=(AMateria const & am)
{
	std::cout 	<< "AMateria assignation overload called for " 
				<< this->type << " = " << am.type << std::endl;
	if (this != &am)
		this->type = am.type;
	return (*this);
}

// ****************************************************************************
// overload of << ostream operator
// ****************************************************************************

std::ostream &	operator<<(std::ostream& os, const AMateria& am)
{
	os << "AMateria type " << am.getType();
	return (os);
}

// ****************************************************************************
// member functions
// ****************************************************************************

std::string const &	AMateria::getType() const //Returns the materia type
{
	return (this->type);
}

void	AMateria::use(ICharacter& target)
{
	if (this->type == "ice")
		std::cout 	<< "\033[31m* shoots an ice bolt at " << target.getName()
					<<" *\033[0m" << std::endl;
	else if (this->type == "cure")
		std::cout 	<< "\033[32m* heals " << target.getName()
					<<"’s wounds *\033[0m" << std::endl;
	return ;
}
