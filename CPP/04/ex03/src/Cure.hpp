/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:11:44 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/15 14:03:31 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include <ostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria
{
	public:
						Cure( void );
						Cure( Cure const & am);
		virtual 		~Cure( void );
		Cure & 			operator=( Cure const & am );
		virtual Cure* 	clone( void ) const;

		virtual void 		use( ICharacter& target );
};
std::ostream &	operator<<(std::ostream& os, const Cure& am);
#endif
