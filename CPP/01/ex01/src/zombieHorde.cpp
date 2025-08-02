/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:09 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/02 23:14:02 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <new>

std::string	int_to_string( int val )
{
	std::string	str;
	int			neg = 1;
	char		c;

	if (val == 0)
		return ("0");
	if (val < 0)
	{
		neg = -1;
		val = val * -1;
	}
	while (val > 0)
	{
		c = '0' + (val % 10);
		str = c + str;
		val = val / 10;
	}
	if (neg == -1)
		str = '-' + str;
	return (str);
}

int count_digits(int n)
{
	if (n == 0)
		return 1;
	int count = 0;
	if (n < 0)
		n = -n;
	while (n != 0) {
		n /= 10;
		count++;
	}
	return (count);
}

std::string fill_zeros( std::string str, std::size_t ndigit )
{
	if (str.size() >= ndigit)
		return str;
	return (std::string(ndigit - str.size(), '0') + str);
}

Zombie* zombieHorde( int N, std::string name )
 {
	int	i = 0;
	int	ndigit = 0;

	Zombie	*new_zombie = new Zombie[N];
	ndigit = count_digits( N );
	for (i = 0; i < N; i++)
		new_zombie[i].init( name + fill_zeros( int_to_string(i + 1), ndigit ) );
	return (new_zombie);
 }