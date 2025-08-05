/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:09:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/05 12:30:27 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FXED_HPP
# define FIXED_HPP

#include <string>

class	Fixed
{
	public:
		Fixed( void );
		~Fixed( void );

		void	complain(std::string level);

	private:
		static std::string	table[4];

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

};
#endif