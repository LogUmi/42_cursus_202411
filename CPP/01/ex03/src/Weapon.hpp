/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 12:22:49 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/03 12:59:37 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
	public :
		Weapon( std::string str );
		~Weapon( void );

		std::string	getType( void ) const;
		void		setType( std::string str );

	private:
		std::string	type;
};

#endif