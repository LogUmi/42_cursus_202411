/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:26:37 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/10 21:08:34 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ScavTrap.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

ScavTrap::ScavTrap( void )
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->max_hit = this->hit_points;
	this->ggate_mode =false;
	std::cout << "ScavTrap default constructor called for " << name << std::endl;
	return ;
}

ScavTrap::ScavTrap( std::string id )
 : 	ClapTrap( id )
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	this->max_hit = this->hit_points;
	this->ggate_mode =false;
	std::cout << "ScavTrap named object constructor called for " << name << std::endl;
	return ;
}

ScavTrap::ScavTrap( const ScavTrap & ct)
 :	ClapTrap()
{
	std::cout << "ScavTrap copy constructor called for " << name << std::endl;
	*this = ct;
	return ;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called for " << name << std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

ScavTrap&	ScavTrap::operator=(const ScavTrap& ct)
{
	std::cout 	<< "ScavTrap copy assignment operator called for " << this->name
				<< " = " << ct.name << std::endl;
	if (this != &ct)
	{
		this->name = ct.name;
		this->attack_damage = ct.attack_damage;
		this->hit_points = ct.hit_points;
		this->energy_points = ct.energy_points;
		this->max_hit = ct.max_hit;
		this->ggate_mode = ct.ggate_mode;
	}
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

void 	ScavTrap::attack(const std::string& target)
{
	int	i = 0;

	std::cout 	<< "\033[33mScavTrap " << this->name;
	if (this->energy_points == 0)
		i = 2;
	if (this->hit_points == 0)
		i++;
	switch(i)
	{
		case 0:
			break ;
		case 1:
			std::cout 	<< " is unable to attack: no more Hit points"
						<< "\033[0m" << std::endl;
			return ;
		case 2:
			std::cout 	<< " is unable to attack: no more Energy points"
						<< "\033[0m" << std::endl;
			return ;
		case 3:
			std::cout 	<< " is unable to attack: no more Energy nor Hit points"
						<< "\033[0m" << std::endl;
			return ;
		default:
			break ;
	}
	this->energy_points--;
	std::cout 	<< " attacks " << target << ", causing " << this->attack_damage
				<< " points of damage!\033[0m" << std::endl;
	return ;
}

void ScavTrap::guardGate()
{
	int	i = 0;

	std::cout 	<< "\033[35mClapTrap " << this->name << ", wich is a ScavTrap, ";
	if (this->energy_points == 0)
		i = 2;
	if (this->hit_points == 0)
		i++;
	if (this->ggate_mode == true)
		i += 4;
	switch(i)
	{
		case 0:
			break ;
		case 1:
			std::cout 	<< "is unable to guard the Gate: no more Hit points"
						<< "\033[0m" << std::endl;
			return ;
		case 2:
			std::cout 	<< "has no energy points but ";
			break ;
		case 3:
			std::cout 	<< "is unable to guard the Gate: no more Energy nor Hit points"
						<< "\033[0m" << std::endl;
			return ;
		case 4:
			std::cout 	<< "is already in Gate keeper mode!"
						<< "\033[0m" << std::endl;
			return ;
		case 5:
			std::cout 	<< "is unable to guard the Gate: no more Hit points"
						<<" and was already in Gate keeper mode!"
						<< "\033[0m" << std::endl;
			return ;
		case 6:
			std::cout 	<< "is already in Gate keeper mode with no more Energy points!"
						<< "\033[0m" << std::endl;
			return ;
		case 7:
			std::cout 	<< "is already in Gate keeper mode but has no more Energy nor Hit points"
						<< "\033[0m" << std::endl;
			return ;
		default:
			break ;
	}
	this->ggate_mode = true;
	std::cout 	<< "is now in Gate keeper mode! 🏰!\033[0m" << std::endl;
	return ;
}