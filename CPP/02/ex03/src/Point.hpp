/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:40:56 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/08 19:00:09 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point( void );
		Point( const float abs, const float ord );
		Point( Point& p );
		~Point( void );

		Point & operator=( const Point & p );
		
		Fixed getx() const;
		Fixed gety() const;
		
	private:
		const Fixed	x;
		const Fixed	y;
};
#endif