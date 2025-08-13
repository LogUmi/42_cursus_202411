/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:26:37 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/13 19:01:05 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Dog.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Dog::Dog( void )
 :	Animal("Dog"),
 	name("Buddy")
{
	std::cout 	<< "Dog default constructor called for " 
				<< this->name << std::endl;
	brain = new Brain();
	brain->gotAnIdea("I'm a default Dog named Buddy which like to run and bark");
	return ;
}

Dog::Dog( std::string id ) 
: 	Animal( "Dog" ),
	name( id )
{
	std::cout << "Dog named object constructor called for " << name << std::endl;
	brain = new Brain();
	brain->gotAnIdea("I'm a named Dog named " + id + " which like to run and bark");
	return ;
}

Dog::Dog( const Dog & ct)
 :	Animal( "Dog" ),
	name( "copy" )
{
	std::cout << "Dog copy constructor called for " << this->name << std::endl;
	brain = new Brain((*ct.brain));
	this->name = ct.name;
	Animal::type = ct.getType();
	return ;
}

Dog::~Dog( void )
{
	std::cout << "Dog destructor called for " << name << std::endl;
	delete brain;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

Dog&	Dog::operator=(const Dog& ct)
{
	std::cout 	<< "Dog copy assignment operator called for " << this->name
				<< " = " << ct.name << std::endl;
	if (this != &ct)
	{
		this->name = ct.name;
		Animal::type = ct.getType();
		*(this->brain) = *(ct.brain);
	}
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

void	Dog::makeSound( void ) const
{
	std::cout << "This Dog makes a Dog sound: WOOOFFF WOOOFFF" << std::endl;
}

std::string	Dog::getName( void ) const
{
	return (this->name);
}

void	Dog::thinking ( void ) const
{
	this->brain->displayIdeas();
	return ;
}

void	Dog::set_idea( const std::string str)
{	
	this->brain->gotAnIdea(str);
	return ;	
}
