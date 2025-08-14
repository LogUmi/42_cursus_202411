/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:09:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/11 21:01:13 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>

class	ClapTrap
{
	public:
		ClapTrap ( void );
		ClapTrap( std::string id );
		ClapTrap( const ClapTrap & ct );
		~ClapTrap( void );
		
		ClapTrap&	operator=(const ClapTrap& ct);

		void 			attack(const std::string& target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);
		std::string		get_name( void ) const;
		unsigned int	get_hit_points( void ) const;
		unsigned int	get_energy_points( void ) const;
		unsigned int	get_attack_damage( void ) const;
	
		protected:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
		unsigned int	max_hit;
		
};
#endif