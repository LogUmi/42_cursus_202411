/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:35:31 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/10 22:14:30 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

DiamondTrap::DiamondTrap( void )
 : 	ClapTrap( "default_clap_name" ),
	name( "default" )
{
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	this->max_hit = this->hit_points;
	std::cout << "DiamondTrap default constructor called for " << name << std::endl;
	return ;
}

DiamondTrap::DiamondTrap( std::string id )
 : 	ClapTrap( id + "_clap_name" ),
	ScavTrap( id ),
	FragTrap( id ),
	name( id )
{
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	this->max_hit = this->hit_points;
	std::cout << "DiamondTrap named object constructor called for " << name << std::endl;
	return ;
}

DiamondTrap::DiamondTrap( const DiamondTrap & ct)
 : 	ClapTrap( ct ),
	ScavTrap( ct ),
	FragTrap( ct ),
	name( ct.name )
{
	std::cout << "DiamondTrap copy constructor called for " << name << std::endl;
	*this = ct;
	return ;
}

DiamondTrap::~DiamondTrap( void )
{
	std::cout << "DiamondTrap destructor called for " << name << std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& ct)
{
	std::cout 	<< "DiamondTrap copy assignment operator called for " << this->name
				<< " = " << ct.name << std::endl;
	if (this != &ct)
	{
		ClapTrap::name = ct.name + "_clap_name";
		this->name = ct.name;
		this->hit_points = ct.hit_points;
		this->energy_points = ct.energy_points;
		this->attack_damage = ct.attack_damage;
		this->max_hit = this->hit_points;
	}
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

void	DiamondTrap::whoAmI()
{
	std::cout 	<< "\033[34mMy DiamondTrap name is: " << this->name
				<< " and my ClapTrap name is: " << ClapTrap::name
				<< "\033[0m" << std::endl;
	return ;
}