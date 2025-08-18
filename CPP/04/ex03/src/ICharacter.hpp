/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:03:30 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/15 16:04:13 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter( void );
		virtual std::string const & getName( void ) const = 0;
		virtual void equip( AMateria* m ) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use( int idx, ICharacter& target ) = 0;
};
#endif