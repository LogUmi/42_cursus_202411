/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:09:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/06 14:00:20 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class	Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed & f);
		~Fixed( void );

		Fixed&	operator=(const Fixed& f);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_value;
		static const int	_nbits = 8;
};
#endif