/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:26:37 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/10 21:54:14 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "FragTrap.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

FragTrap::FragTrap( void )
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	this->max_hit = this->hit_points;
	std::cout << "FragTrap default constructor called for " << name << std::endl;
	return ;
}

FragTrap::FragTrap( std::string id )
 : 	ClapTrap( id )
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	this->max_hit = this->hit_points;
	std::cout << "FragTrap named object constructor called for " << name << std::endl;
	return ;
}

FragTrap::FragTrap( const FragTrap & ct)
 :	ClapTrap()
{
	std::cout << "FragTrap copy constructor called for " << name << std::endl;
	*this = ct;
	return ;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called for " << name << std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

FragTrap&	FragTrap::operator=(const FragTrap& ct)
{
	std::cout 	<< "FragTrap copy assignment operator called for " << this->name
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

void FragTrap::highFivesGuys(void)
{
	int	i = 0;

	std::cout 	<< "\033[36mClapTrap " << this->name << ", wich is a FragTrap, ";
	if (this->energy_points == 0)
		i = 2;
	if (this->hit_points == 0)
		i++;
	switch(i)
	{
		case 0:
			break ;
		case 1:
			std::cout 	<< "is unable to request High fives: no more Hit points"
						<< "\033[0m" << std::endl;
			return ;
		case 2:
			break ;
		case 3:
			std::cout 	<< "is unable to request High fives: no more Energy nor Hit points"
						<< "\033[0m" << std::endl;
			return ;
		default:
			break ;
	}
	std::cout 	<< "says: High five, guys! ✋!\033[0m"
				<< std::endl;
	return ;
}