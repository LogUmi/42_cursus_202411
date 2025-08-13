/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 22:56:32 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/13 23:10:33 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	type;
	
	public:
		AMateria(std::string const & type);

		std::string const &	getType() const; //Returns the materia type
		virtual AMateria* 	clone() const = 0;
		virtual void 		use(ICharacter& target);
};
#endif