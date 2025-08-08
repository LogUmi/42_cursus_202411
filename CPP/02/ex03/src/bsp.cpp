/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:53:51 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/08 18:58:17 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	v1;
	Fixed	v2;
	Fixed	v3;
	
	v1 = ((b.getx() - point.getx())*(a.getx() - point.gety()));
	v1 = v1 -((b.gety() - point.gety()) - (a.gety() - point.getx()));
	v2 = ((b.getx() - point.getx())*(c.getx() - point.gety()));
	v2 = v2 -((b.gety() - point.gety()) - (c.gety() - point.getx()));
	v3 = ((a.getx() - point.getx())*(c.getx() - point.gety()));
	v3 = v3 -((a.gety() - point.gety()) - (c.gety() - point.getx()));
	if (v1 == 0 || v2 == 0 || v3 == 0)
		return (false);
	if ((v1 > 0 && v2 > 0 && v3 > 0) || (v1 < 0 && v2 < 0 && v3 < 0))
		return (true);
	return (false);
}