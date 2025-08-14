/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:09:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/13 22:45:14 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>

class	AAnimal
{
	public:
					AAnimal( void );
					AAnimal( std::string id );
					AAnimal( const AAnimal & ct );
		virtual		~AAnimal( void );
		AAnimal&	operator=(const AAnimal& ct);

		virtual void	makeSound() const = 0;
		std::string		getType( void ) const;

		protected:
		std::string		type;
};
#endif