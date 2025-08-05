/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:09:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/05 19:03:12 by lgerard          ###   ########.fr       */
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
		struct 				dispatch_entry
		{
			std::string		name;
			functions		function;
		};
		dispatch_entry	table[4];

		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

};
#endif