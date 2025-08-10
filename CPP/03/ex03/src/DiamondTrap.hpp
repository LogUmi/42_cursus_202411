/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:35:03 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/10 21:14:37 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp" 

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap ( void );
		DiamondTrap( std::string id );
		DiamondTrap( const DiamondTrap & ct );
		~DiamondTrap( void );

		DiamondTrap&	operator=( const DiamondTrap& ct );

		using			ScavTrap::attack;
		void 			whoAmI();

	private:
		std::string	name;

};
#endif