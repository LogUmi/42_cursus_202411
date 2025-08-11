/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:18 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/10 21:55:50 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

ClapTrap::ClapTrap( void )
 : 	name("default"),
	hit_points(10),
	energy_points(10),
	attack_damage(0)
{
	this->max_hit = this->hit_points;
	std::cout << "ClapTrap default constructor called for " << name << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string id )
 : 	name(id),
	hit_points(10),
	energy_points(10),
	attack_damage(0)
{
	this->max_hit = this->hit_points;
	std::cout << "ClapTrap named object constructor called for " << name << std::endl;
	return ;
}

ClapTrap::ClapTrap( const ClapTrap & ct)
 :	name( "default" )
{
	std::cout << "ClapTrap copy constructor called for " << name << std::endl;
	*this = ct;
	return ;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "ClapTrap destructor called for " << name << std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

ClapTrap&	ClapTrap::operator=(const ClapTrap& ct)
{
	std::cout 	<< "ClapTrap copy assignment operator called for " << this->name
				<< " = " << ct.name << std::endl;
	if (this != &ct)
	{
		this->name = ct.name;
		this->attack_damage = ct.attack_damage;
		this->hit_points = ct.hit_points;
		this->energy_points = ct.energy_points;
		this->max_hit = ct.max_hit;
	}
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

void	ClapTrap::attack(const std::string& target)
{
	int	i = 0;

	std::cout 	<< "\033[33mClapTrap " << this->name;
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

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout 	<< "\033[31mClapTrap " << this->name << " has taken " << amount 
				<< " points of damage";
	if (amount >= this->hit_points)
	{
		this->hit_points = 0;
		std::cout << " and has no Hit points left";
	}
	else
	{
		this->hit_points -= amount;
		std::cout << " and has " << this->hit_points << " Hit points left";
	}
	std::cout	<< "!\033[0m" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	int	i = 0;

	std::cout 	<< "\033[32mClapTrap " << this->name;
	if (this->energy_points == 0)
		i = 2;
	if (this->hit_points == 0)
		i++;
	if (this->hit_points >= this->max_hit && this->energy_points != 0)
		i = 4;
	switch(i)
	{
		case 0:
			break ;
		case 1:
			std::cout 	<< " is unable to repair himself: no more Hit points"
						<< "\033[0m" << std::endl;
			return ;
		case 2:
			std::cout 	<< " is unable to repair himself: no more Energy points"
						<< "\033[0m" << std::endl;
			return ;
		case 3:
			std::cout 	<< " is unable to repair himself: no more Energy nor Hit points"
						<< "\033[0m" << std::endl;
			return ;
		case 4:
			std::cout 	<< " is unable to repair himself: Hit points cannot exceed the "
						<< this->max_hit << " points already in place"
						<< "\033[0m" << std::endl;
			return ;
		default:
			break ;
	}
	std::cout 	<< " repairs himself " << amount << ", receiving ";
	this->hit_points += amount;
	this->energy_points--;
	if (this->hit_points <= this->max_hit)
		std::cout	<< amount << " Hit points!\033[0m" << std::endl;
	else
	{
		std::cout	<< "only " << (this->max_hit - (this->hit_points - amount)) 
					<< " Hit points to reach max value!\033[0m" << std::endl;
		this->hit_points = this->max_hit;
	}
	return ;
}

std::string		ClapTrap::get_name( void ) const
{
	return (this->name);
}

unsigned int	ClapTrap::get_hit_points( void ) const
{
	return (this->hit_points);
}

unsigned int	ClapTrap::get_energy_points( void ) const
{
	return (this->energy_points);
}

unsigned int	ClapTrap::get_attack_damage( void ) const
{
	return (this->attack_damage);
}