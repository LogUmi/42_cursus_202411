/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:26:41 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/12 00:12:45 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog ( void );
		Dog (std::string id);
		Dog( const Dog & ct );
		virtual	~Dog( void );
		Dog&	operator=( const Dog& ct );

		virtual void	makeSound( void ) const;
		virtual std::string		getName( void ) const;

	private:
		std::string	name;
};
#endif