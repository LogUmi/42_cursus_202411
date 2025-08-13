/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 21:26:41 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/13 18:53:28 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat ( void );
		Cat (std::string id);
		Cat( const Cat & ct );
		virtual	~Cat( void );
		Cat&	operator=( const Cat& ct );

		virtual void	makeSound( void ) const;
		std::string		getName( void ) const;
		void			thinking ( void ) const;
		void			set_idea( const std::string str );

	private:
		std::string	name;
		Brain*		brain;
};
#endif