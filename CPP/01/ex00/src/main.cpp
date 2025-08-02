/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/02 21:32:09 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

 Zombie*	newZombie( std::string name );
 void 		randomChump( std::string name );

int	main(void)
{
	Zombie	*new_zombie = newZombie( "Zombie dynamique");
	std::cout 	<< "Zombie dynamique seems to be a bit lazy let's tickle him with a stick"
				<< std::endl;
	(*new_zombie).announce();
	randomChump ("Zombie statique");
	delete new_zombie;
	return (0);
}