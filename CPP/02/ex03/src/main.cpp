/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/08 20:56:13 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

std::string in_or_out(bool i)
{
	if (i == true)
		return (std::string("inside the triangle abc"));
	return (std::string("outside the triangle abc"));
}

int main( void )
{
	Point a;
	Point b(5, 5);
	Point c(10.0f, -1.0f);
	Point test1(-1, 4);
	Point test2(2, 2);
	Point test3(3, 4);
	Point test4(5.0f, 5.0f);
	Point test5(5, 1);
	Point test6(5, -0.5f);
	Point test7(7, 0);
	Point test8(6.5f, 2.5f);
	Point test9(10, 3);
	Point test10(7, -2.5f);
	Point test11(1, 0);
	Point test12(-1, -2);
	std::cout 	<< "triangle a x" << a.getx() << " / y" << a.gety() << std::endl
				<< "         b x" << b.getx() << " / y" << b.gety() << std::endl
				<< "         c x" << c.getx() << " / y" << c.gety() << std::endl
				<< std::endl;
	std::cout	<< "test 1     x" << test1.getx() << " / y" << test1.gety() 
				<<"  Result: " << in_or_out(bsp(a, b, c, test1)) << std::endl;
	std::cout	<< "test 2     x" << test2.getx() << " / y" << test2.gety() 
				<<"  Result: " << in_or_out(bsp(a, b, c, test2)) << std::endl;
	std::cout	<< "test 3     x" << test3.getx() << " / y" << test3.gety() 
				<<"  Result: " << in_or_out(bsp(a, b, c, test3)) << std::endl;
	std::cout	<< "test 4     x" << test4.getx() << " / y" << test4.gety() 
				<<"  Result: " << in_or_out(bsp(a, b, c, test4)) << std::endl;
	std::cout	<< "test 5     x" << test5.getx() << " / y" << test5.gety()
				<<"  Result: " << in_or_out(bsp(a, b, c, test5)) << std::endl;
	std::cout	<< "test 6     x" << test6.getx() << " / y" << test6.gety() 
				<<"  Result: " << in_or_out(bsp(a, b, c, test6)) << std::endl;
	std::cout	<< "test 7     x" << test7.getx() << " / y" << test7.gety() 
				<<"  Result: " << in_or_out(bsp(a, b, c, test7)) << std::endl;
	std::cout	<< "test 8     x" << test8.getx() << " / y" << test8.gety() 
				<<"  Result: " << in_or_out(bsp(a, b, c, test8)) << std::endl;
	std::cout	<< "test 9     x" << test9.getx() << " / y" << test9.gety() 
				<<"  Result: " << in_or_out(bsp(a, b, c, test9)) << std::endl;
	std::cout	<< "test 10     x" << test10.getx() << " / y" << test10.gety() 
				<<"  Result: " << in_or_out(bsp(a, b, c, test10)) << std::endl;
	std::cout	<< "test 11     x" << test11.getx() << " / y" << test11.gety()
				<<"  Result: " << in_or_out(bsp(a, b, c, test5)) << std::endl;
	std::cout	<< "test 12     x" << test12.getx() << " / y" << test12.gety() 
				<<"  Result: " << in_or_out(bsp(a, b, c, test12)) << std::endl;	
	return (0);
}
