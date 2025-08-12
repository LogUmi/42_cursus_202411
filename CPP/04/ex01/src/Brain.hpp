/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:33:42 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/12 17:39:25 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class	Brain
{
	public:
		Brain( void );
		Brain( std::string id );
		Brain( const Brain & ct );
		virtual	~Brain( void );
		Brain&	operator=(const Brain& ct);

		virtual void		makeSound() const;
		std::string	getType( void ) const;

		protected:
		std::string		type;
};
#endif