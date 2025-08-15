/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:02:43 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/15 13:59:40 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Character.hpp"
#include "AMateria.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Character::Character( void )
 :	name("John DOE")
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inv[i] = 0;
	for (int i = 0; i < 100; i++)
		this->ground[i] = 0;
	return ;
}

Character::Character(std::string const & name)
 :	name(name)
{
	std::cout 	<< "Character typed constructor called for " 
				<< this->name << std::endl;
	for (int i = 0; i < 4; i++)
		this->inv[i] = 0;
	for (int i = 0; i < 100; i++)
		this->ground[i] = 0;
	return ;
}

Character::Character(Character const & am)
 :	name (am.name)
{
	std::cout 	<< "Character copy constructor called for " 
				<< this->name << std::endl;
	for (int i = 0; i < 4; ++i)
        this->inv[i] = am.inv[i] ? am.inv[i]->clone() : 0;
    for (int i = 0; i < 100; ++i)
       this->ground[i] = 0;
	return ;
}

Character::~Character( void )
{
	std::cout 	<< "Character destructor called for " 
				<< this->name << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i] != 0)
		{
			delete this->inv[i];
			this->inv[i] = 0;
		}
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->ground[i] != 0)
		{
			delete this->ground[i];
			this->ground[i] = 0;
		}
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
	{
		for (int i = 0; i < 4; ++i) 
		{ 
			delete this->inv[i];
			this->inv[i] = 0;
		}
        // libérer le sol (sinon fuite si remise à 0)
        for (int i = 0; i < 100; ++i)
		{ 
			delete this->ground[i];
			this->ground[i] = 0;
		}
		this->name = am.name;
		for (int i = 0; i < 4; ++i)
        	this->inv[i] = am.inv[i] ? am.inv[i]->clone() : 0;
   		for (int i = 0; i < 100; ++i)
       	this->ground[i] = 0;
	}
	return (*this);
}

// ****************************************************************************
// overload of << ostream operator
// ****************************************************************************

std::ostream &	operator<<(std::ostream& os, const Character& am)
{
	os 	<< "Character " << am.getName() << " has in inventory:" << std::endl;
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

std::string const &		Character::getName( void ) const
{
	return (this->name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->inv[i] == 0)
		{
			inv[i] = m;
			return ;
		}
	}
	return ;
}
void 	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
    if (!this->inv[idx])
		return ; 
	for (int i = 0; i < 100; i++)
	{
		if (this->ground[i] == 0)
		{
			this->ground[i] = this->inv[idx];
			this->inv[idx] = 0;
			return ;
		}
	}
	return ;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4)
		return ;
    if (!this->inv[idx])
		return ;
	this->inv[idx]->use( target );
	return ;
}

AMateria const *	Character::getInv(int const idx) const
{
	return (this->inv[idx]);
}

bool	Character::checkInventory( void ) const
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