/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:09:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/11 22:40:39 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <string>

class	WrongAnimal
{
	public:
		WrongAnimal( void );
		WrongAnimal( std::string id );
		WrongAnimal( const WrongAnimal & ct );
		~WrongAnimal( void );
		WrongAnimal&	operator=(const WrongAnimal& ct);

		void			makeSound() const;
		std::string		getType( void ) const;

		protected:
		std::string		type;
};
#endif