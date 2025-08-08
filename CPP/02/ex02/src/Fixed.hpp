/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:09:22 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/08 13:04:57 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	public:
		Fixed( void );
		Fixed( const Fixed & f);
		Fixed( const int i);
		Fixed( const float f);
		~Fixed( void );

		Fixed&	operator=( const Fixed& f );
		bool	operator>( const Fixed& f ) const;
		bool	operator<( const Fixed& f ) const;
		bool	operator>=( const Fixed& f ) const;
		bool	operator<=( const Fixed& f ) const;
		bool	operator==( const Fixed& f ) const;
		bool	operator!=( const Fixed& f ) const;
		Fixed	operator+( const Fixed& f );
		Fixed	operator-( const Fixed& f );
		Fixed	operator*( const Fixed& f );
		Fixed	operator/( const Fixed& f );
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		
		static Fixed&		min(Fixed & a, Fixed & b);
		static const Fixed&	min(const Fixed & a, const Fixed & b);
		static Fixed&		max(Fixed & a, Fixed & b);
		static const Fixed&	max(const Fixed & a, const Fixed & b);

	private:
		int					_value;
		static const int	_nbits = 8;
		
};

std::ostream & operator<<(std::ostream & o, Fixed const & val);

#endif