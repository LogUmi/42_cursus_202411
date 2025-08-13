/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:09:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/13 16:26:06 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class	Animal
{
	public:
		Animal( void );
		Animal( std::string id );
		Animal( const Animal & ct );
		virtual	~Animal( void );
		Animal&	operator=(const Animal& ct);

		virtual void	makeSound() const;
		std::string		getType( void ) const;

		protected:
		std::string		type;
};
#endif