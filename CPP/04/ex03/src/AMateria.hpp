/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:56:32 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/14 12:49:06 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <ostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;
	
	public:
							AMateria( void );
							AMateria( std::string const & type);
							AMateria( const AMateria& am );
		virtual 			~AMateria( void );
		AMateria & 			operator=( AMateria const & am );
		virtual AMateria* 	clone( void ) const = 0;

		std::string const &	getType( void ) const; //Returns the materia type
		virtual void 		use( ICharacter& target );
};
std::ostream &	operator<<(std::ostream& os, const AMateria& am);
#endif