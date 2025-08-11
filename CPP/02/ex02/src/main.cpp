/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/08 17:08:33 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);
	/*Fixed a;
	Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );
	Fixed c(2);

	std::cout << a << " < " << c << " = " << (a < c) << std::endl;
	std::cout << a << " > " << c << " = " << (a > c) << std::endl;
	std::cout << c << " < " << a << " = " << (c < a) << std::endl;
	std::cout << c << " > " << a << " = " << (c > a) << std::endl;
	std::cout << c << " == " << a << " = " << (c == a) << std::endl;
	std::cout << a << " == " << c << " = " << (a == c) << std::endl;
	std::cout << c << " != " << a << " = " << (c != a) << std::endl;
	std::cout << a << " != " << c << " = " << (a != c) << std::endl;
	std::cout << a << " <= " << c << " = " << (a <= c) << std::endl;
	std::cout << a << " >= " << c << " = " << (a >= c) << std::endl;
	std::cout << c << " <= " << a << " = " << (c <= a) << std::endl;
	std::cout << c << " >= " << a << " = " << (c >= a) << std::endl;
	a = a + c;
	std::cout << a << " < " << a << " = " << (a < c) << std::endl;
	std::cout << a << " > " << c << " = " << (a > c) << std::endl;
	std::cout << c << " < " << a << " = " << (c < a) << std::endl;
	std::cout << c << " > " << a << " = " << (c > a) << std::endl;
	std::cout << c << " == " << a << " = " << (c == a) << std::endl;
	std::cout << a << " == " << c << " = " << (a == c) << std::endl;
	std::cout << c << " != " << a << " = " << (c != a) << std::endl;
	std::cout << a << " != " << c << " = " << (a != c) << std::endl;
	c = c - b;
	std::cout << a << " < " << a << " = " << (a < c) << std::endl;
	std::cout << a << " > " << c << " = " << (a > c) << std::endl;
	std::cout << c << " < " << a << " = " << (c < a) << std::endl;
	std::cout << c << " > " << a << " = " << (c > a) << std::endl;
	std::cout << c << " == " << a << " = " << (c == a) << std::endl;
	std::cout << a << " == " << c << " = " << (a == c) << std::endl;
	std::cout << c << " != " << a << " = " << (c != a) << std::endl;
	std::cout << a << " != " << c << " = " << (a != c) << std::endl;
	a = 5;
	std::cout << "a(5) * 2 / 3 " << " = " << (a * 2 / 3) << std::endl;
	c = Fixed(2 / 3);
	std::cout << "a(5) * c (2/3) " << " = " << (a * c) << std::endl;
	c = (Fixed(2) / Fixed(3));
	std::cout << "a(5) * c (2/3) " << " = " << (a * c) << std::endl;
	a = 0;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return (0);*/
}
