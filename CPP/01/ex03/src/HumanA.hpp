/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 13:17:33 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/03 13:29:54 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	public:
		HumanA( std::string id, Weapon& item );
		~HumanA( void );

		void	attack( void ) const;

	private:
		std::string	name;
		Weapon&		weapon;
};

#endif