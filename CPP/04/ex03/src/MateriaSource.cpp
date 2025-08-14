/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:08:38 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/14 18:16:25 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "MateriaSource.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

MateriaSource::MateriaSource( void )
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inv[i] = 0;
	return ;
}

MateriaSource::MateriaSource(MateriaSource const & am)
{
	std::cout 	<< "MateriaSource copy constructor called" 
				<< std::endl;
	for (int i = 0; i < 4; i++)
		inv[i] = 0;
	return ;
}

MateriaSource::~MateriaSource( void )
{
	std::cout 	<< "MateriaSource destructor called for " 
				<< this->name << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inv[i] != 0)
			delete inv[i];
	}
	for (int i = 0; i < 100; i++)
	{
		if (ground[i] != 0)
			delete inv[i];			
	}
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

MateriaSource &	MateriaSource::operator=(MateriaSource const & am)
{
	std::cout 	<< "MateriaSource assignation overload called for " 
				<< this->name << " = " << am.name << std::endl;
	if (this != &am)
		this->name = am.name;
	return (*this);
}

// ****************************************************************************
// overload of << ostream operator
// ****************************************************************************

std::ostream &	operator<<(std::ostream& os, const MateriaSource& am)
{
	os 	<< "MateriaSource " << am.getName() << " has in inventory:" << std::endl;
	for (int i = 0; i < 4; i++)
		os 	<< "slot " << i + 1 << ": " << am.getInv(i) << std::endl;		
	return (os);
}

// ****************************************************************************
// member functions
// ****************************************************************************

std::string const &		MateriaSource::getName( void ) const
{
	return (this->name);
}

void	MateriaSource::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i] != 0)
			inv[i] = m;
	}	
	return ;
}
void 	MateriaSource::unequip(int idx)
{
	this->inv[idx] = 0;
	return ;
}

void	MateriaSource::use(int idx, IMateriaSource& target)
{
	(*this->inv[idx]).use( target );
	delete this->inv[idx];
	this->inv[idx] = 0;
	return ;	
}

AMateria const &	MateriaSource::getInv(int const idx) const
{
	return ((*this->inv[idx]));
}