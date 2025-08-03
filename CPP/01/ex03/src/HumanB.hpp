/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 13:17:33 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/03 14:17:54 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB( std::string id );
		~HumanB( void );

		void	attack( void ) const;
		void	setWeapon( Weapon& item );

	private:
		std::string	name;
		Weapon*	weapon;
};

#endif