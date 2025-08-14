/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:26:41 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/13 22:16:22 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	public:
		Dog ( void );
		Dog (std::string id);
		Dog( const Dog & ct );
		~Dog( void );
		Dog&	operator=( const Dog& ct );

		void	makeSound( void ) const;
		std::string		getName( void ) const;
		void			thinking ( void ) const;
		void			set_idea( const std::string str);

	private:
		std::string	name;
		Brain* 		brain;
};
#endif