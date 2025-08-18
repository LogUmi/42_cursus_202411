/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:03:30 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/15 15:49:39 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <ostream>
# include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
	private:
		std::string	name;
		AMateria*	inv[4];
		AMateria*	ground[100];
		
	public:
							Character( void );
							Character( std::string const & name);
							Character( const Character& am );
		virtual 			~Character( void );
		Character & 		operator=( Character const & am );
		
		virtual std::string const &		getName() const;
		virtual void 					equip(AMateria* m);
		virtual void 					unequip(int idx);
		virtual void 					use(int idx, ICharacter& target);
		AMateria const *				getInv(int const idx) const;
		bool							checkInventory( void ) const;
};
std::ostream &	operator<<(std::ostream& os, const Character& am);
#endif