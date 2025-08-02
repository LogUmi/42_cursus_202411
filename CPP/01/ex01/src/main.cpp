/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/02 22:57:25 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde( int N, std::string name );

int	main(void)
{
	int		N = 10;
	int		i = 0;
	Zombie	*new_zombie;
	
	new_zombie = zombieHorde( N, "Weirdo" );
	for (i = 0; i < N; i++)
		(new_zombie[i]).announce();
	delete [] new_zombie;
	return (0);
}