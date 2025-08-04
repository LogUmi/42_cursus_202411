/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:09:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/04 21:51:13 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class	Harl
{
	public:
		Harl( void );
		~Harl( void );

		void	complain(std::string level );

	private:
		typedef 			void (Harl::*functions)();
		struct 				s_dispatch
		{
			std::string		name;
			functions		function;
		};
		s_dispatch	table[4];

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

};
#endif