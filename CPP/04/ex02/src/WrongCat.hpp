/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:26:41 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/12 00:26:24 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
# define WrongCat_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat ( void );
		WrongCat (std::string id);
		WrongCat( const WrongCat & ct );
		~WrongCat( void );
		WrongCat&	operator=( const WrongCat& ct );

		void			makeSound( void ) const;
		std::string		getName( void ) const;

	private:
		std::string	name;
};
#endif