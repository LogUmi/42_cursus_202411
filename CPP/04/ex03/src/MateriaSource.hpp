/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:06:29 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/15 15:52:33 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <ostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
	private:
		AMateria* inv[4];
		
	public:
		MateriaSource ( void );
		MateriaSource ( MateriaSource const & ms );
		virtual ~MateriaSource();
		MateriaSource &	operator=(MateriaSource const & ms);

		virtual void 		learnMateria(AMateria* am);
		virtual AMateria* 	createMateria(std::string const & type);
		AMateria const *	getInv(int const idx) const;
		bool				checkInventory( void ) const;
};
std::ostream &	operator<<(std::ostream& os, const MateriaSource& am);
#endif