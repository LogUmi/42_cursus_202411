/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:12:56 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/15 14:03:21 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include <ostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
						Ice( void );
						Ice( Ice const & type);
		virtual 		~Ice( void );
		Ice & 			operator=( Ice const & am );
		virtual Ice* 	clone( void ) const;

		virtual void 		use( ICharacter& target );
};
std::ostream &	operator<<(std::ostream& os, const Ice& am);
#endif
