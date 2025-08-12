/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 21:48:55 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/12 22:58:53 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "Brain.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Brain::Brain( void )
 :	count(1)
{
	ideas[0] = "I have a brain";
	std::cout << "Brain default constructor called " << std::endl;
	return ;
}

Brain::Brain( const Brain & ct)
: 	count(0)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = ct;
	return ;
}

Brain::~Brain( void )
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

// ****************************************************************************
// overload of assignation operator
// ****************************************************************************

Brain&	Brain::operator=(const Brain& ct)
{
	std::cout 	<< "Brain copy assignment operator called" << std::endl;
	if (this != &ct)
	{
		this->count = ct.count;
		for (int i = 0; i < ct.count; i++)
			this->ideas[i] = ct.ideas[i];
	}
	return (*this);
}

// ****************************************************************************
// member functions
// ****************************************************************************

void	Brain::displayIdeas( void ) const
{
	std::cout << "\033[034has " << this->count << "ideas:";
	for (int i = 0; i < this->count; i++)
		std::cout 	<< std::endl << std::setfill ('0') << std::setw (3) << (i + 1)
					<<  ". " << this->ideas[i];
	std::cout << "\033[0m]" << std::endl;
	return ;
}

int	Brain::get_n_ideas (void ) const
{
	return (this->count);
}

void	Brain::gotAnIdea(const std::string str)
{
	if (this->count >= 100)
		std::cout << "\033[033mBrain can't have mode ideas\033[0m" << std::endl;
	else
	{
		this->ideas[this->count] = str;
		this->count++;
	}
	return ;
}