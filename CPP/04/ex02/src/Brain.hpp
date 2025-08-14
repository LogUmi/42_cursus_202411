/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:33:42 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/12 23:35:53 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class	Brain
{
	public:
		Brain( void );
		Brain( const Brain & ct );
		virtual	~Brain( void );
		Brain&	operator=(const Brain& ct);

		void	displayIdeas( void ) const;
		int		get_n_ideas (void ) const;
		void	gotAnIdea(const std::string str);

	private:
		std::string	ideas[100];
		int			count;
};
#endif