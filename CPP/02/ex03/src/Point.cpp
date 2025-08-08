/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:56:53 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/08 19:01:43 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// ****************************************************************************
// Constructors and destructor
// ****************************************************************************

Point::Point( void ) : x(0), y(0)
{
	return ;
}

Point::Point( const float abs, const float ord) : x(abs), y(ord)
{
	return ;
}
Point::Point( Point & p ) : x(p.x), y(p.y)
{
	return ;
}

Point::~Point( void )
{
	return ;
}

Point & Point::operator=( const Point & p )
{
	(void)p;
	return (*this);
}


// ****************************************************************************
// member functions
// ****************************************************************************

Fixed Point::getx() const
{
	return (this->x);
}

Fixed Point::gety() const
{
	return (this->y);
}
