/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:12:56 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/14 12:50:20 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include <ostream>
# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
						Ice( void );
						Ice( std::string typ);
						Ice( std::string const & type);
		virtual 		~Ice( void );
		Ice & 			operator=( Ice const & am );
		virtual Ice* 	clone( void ) const;

};
std::ostream &	operator<<(std::ostream& os, const Ice& am);
#endif
