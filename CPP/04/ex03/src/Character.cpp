/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:02:43 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/14 18:14:47 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Character.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Character::Character( void )
 :	name("John DOE")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		inv[i] = 0;
	for (int i = 0; i < 100; i++)
		ground[i] = 0;
	return ;
}

Character::Character(std::string const & name)
 :	name(name)
{
	std::cout 	<< "Character typed constructor called for " 
				<< this->name << std::endl;
	for (int i = 0; i < 4; i++)
		inv[i] = 0;
	for (int i = 0; i < 100; i++)
		ground[i] = 0;
	return ;
}

Character::Character(Character const & am)
 :	name ("copy")
{
	std::cout 	<< "Character copy constructor called for " 
				<< this->name << std::endl;
	return ;
}

Character::~Character( void )
{
	std::cout 	<< "Character destructor called for " 
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

Character &	Character::operator=(Character const & am)
{
	std::cout 	<< "Character assignation overload called for " 
				<< this->name << " = " << am.name << std::endl;
	if (this != &am)
		this->name = am.name;
	return (*this);
}

// ****************************************************************************
// overload of << ostream operator
// ****************************************************************************

std::ostream &	operator<<(std::ostream& os, const Character& am)
{
	os 	<< "Character " << am.getName() << " has in inventory:" << std::endl;
	for (int i = 0; i < 4; i++)
		os 	<< "slot " << i + 1 << ": " << am.getInv(i) << std::endl;		
	return (os);
}

// ****************************************************************************
// member functions
// ****************************************************************************

std::string const &		Character::getName( void ) const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i] != 0)
			inv[i] = m;
	}	
	return ;
}
void 	Character::unequip(int idx)
{
	this->inv[idx] = 0;
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	(*this->inv[idx]).use( target );
	delete this->inv[idx];
	this->inv[idx] = 0;
	return ;	
}

AMateria const &	Character::getInv(int const idx) const
{
	return ((*this->inv[idx]));
}