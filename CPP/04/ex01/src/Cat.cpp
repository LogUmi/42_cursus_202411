/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:26:37 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/12 23:34:12 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cat.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Cat::Cat( void )
 :	Animal ( "Cat" ),
 	name("Kitty")
{
	std::cout 	<< "Cat default constructor called for " 
				<< this->name << std::endl;
	brain = new Brain();
	brain->gotAnIdea("I'm a default Cat named Kitty which like to jump up the roofs");
	return ;
}

Cat::Cat( std::string id ) 
: 	Animal( "Cat" ),
	name( id )
{
	std::cout << "Cat named object constructor called for " << name << std::endl;
	brain = new Brain();
	brain->gotAnIdea("I'm a named Cat named " + id + " which like to jump up to the roofs");
	return ;
}

Cat::Cat( const Cat & ct)
 :	Animal( "Cat" ),
	name( "copy" )
{
	std::cout << "Cat copy constructor called for " << name << std::endl;
	brain = new Brain((*ct.brain));
	*this = ct;
	return ;
}

Cat::~Cat( void )
{
	std::cout << "Cat destructor called for " << name << std::endl;
	delete brain;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

Cat&	Cat::operator=(const Cat& ct)
{
	std::cout 	<< "Cat copy assignment operator called for " << this->name
				<< " = " << ct.name << std::endl;
	if (this != &ct)
	{
		this->name = ct.name;
		Animal::type = ct.getType();
		this->brain = ct.brain;
	}
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

void	Cat::makeSound( void ) const
{
	std::cout << "This Cat makes a Cat sound: MEEEEOOOOOOW " << std::endl;
}

std::string	Cat::getName( void ) const
{
	return (this->name);
}