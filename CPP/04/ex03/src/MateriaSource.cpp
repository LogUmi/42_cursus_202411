/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:08:38 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/15 13:45:27 by lgerard          ###   ########.fr       */
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

MateriaSource::MateriaSource(MateriaSource const & ms)
{
	std::cout 	<< "MateriaSource copy constructor called" 
				<< std::endl;
	for (int i = 0; i < 4; ++i)
        	this->inv[i] = ms.inv[i] ? ms.inv[i]->clone() : 0;
	return ;
}

MateriaSource::~MateriaSource( void )
{
	std::cout 	<< "MateriaSource destructor called for " 
				<< std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (inv[i] != 0)
		{
			delete inv[i];
			inv[i] = 0;
		}
	}
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

MateriaSource &	MateriaSource::operator=(MateriaSource const & ms)
{
	std::cout 	<< "MateriaSource assignation overload called" 
				<< std::endl;
	if (this != &ms)
	{
		for (int i = 0; i < 4; ++i)
		{
			delete this->inv[i];
			this->inv[i] = 0;
		}
		for (int i = 0; i < 4; ++i)
        	this->inv[i] = ms.inv[i] ? ms.inv[i]->clone() : 0;
	}
	return (*this);
}

// ****************************************************************************
// overload of << ostream operator
// ****************************************************************************

std::ostream &	operator<<(std::ostream& os, const MateriaSource& am)
{
	os 	<< "MateriaSource has in inventory:" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (am.getInv(i)) 
			os 	<< "slot " << i+1 << ": " << am.getInv(i)->getType()
				<< std::endl;
		else 
			os 	<< "slot " << i+1 << ": (empty)" << std::endl;	
	}
	return (os);
}

// ****************************************************************************
// member functions
// ****************************************************************************

AMateria const *	MateriaSource::getInv(int const idx) const
{
	return (this->inv[idx]);
}

void	MateriaSource::learnMateria(AMateria* am)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i] == 0)
		{
			this->inv[i] = am;
			return ;
		}
	}
	return ;
}
AMateria* 	MateriaSource::createMateria(std::string const & type)
{
	if (type.empty())
		return (0);
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i] && this->inv[i]->getType() == type)
		{
			return (this->inv[i]->clone());
		}
	}
	return (0);
}

bool	MateriaSource::checkInventory( void ) const
{
	int	j = 0;
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i] != 0)
			j++;
	}
	if (j == 4)
		return (false); // return false if inventory full
	return (true);
}