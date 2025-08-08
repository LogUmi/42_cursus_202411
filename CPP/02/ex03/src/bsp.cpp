/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:53:51 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/08 23:12:51 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	v1;
	Fixed	v2;
	Fixed	v3;
	
	v1 = (b.getx() - a.getx()) * (point.gety() - a.gety()) 
	         - (b.gety() - a.gety()) * (point.getx() - a.getx());
	v2 = (c.getx() - b.getx()) * (point.gety() - b.gety()) 
	         - (c.gety() - b.gety()) * (point.getx() - b.getx());
	v3 = (a.getx() - c.getx()) * (point.gety() - c.gety()) 
	         - (a.gety() - c.gety()) * (point.getx() - c.getx());
	std::cout << "v1 " << v1 << "  v2 " << v2 << "  v3 " << v3 << ": ";
	if (v1 == 0 || v2 == 0 || v3 == 0)
		return (false);
	if ((v1 > 0 && v2 > 0 && v3 > 0) || (v1 < 0 && v2 < 0 && v3 < 0))
		return (true);
	return (false);
}