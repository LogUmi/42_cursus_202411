/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/10 18:41:57 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

void	write_clap(ClapTrap & a)
{
	std::cout	<< a.get_name() << " is ClapTrap and has: " << a.get_energy_points()
				<< " Energy points, " << a.get_hit_points() << " Hit points, "
				<< a.get_attack_damage() << " attack damage" << std::endl;
	return ;
}

int	main(void)
{
	std::cout << "\033[34m*** Constructing ***\033[0m" << std::endl << std::endl;
	ClapTrap a("One");
	write_clap(a);
	ClapTrap b("Two");
	write_clap(b);
	std::cout 	<< std::endl << "*** Testing member functions ***" 
				<< std::endl << std::endl;
	a.attack("some other ClapTrap");
	a.takeDamage(5);
	a.beRepaired(3);
	a.beRepaired(5);
	a.takeDamage(10);
	a.attack("some other other ClapTrap");
	a.beRepaired(5);
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("everyone");
	b.beRepaired(3);
	{
		std::cout 	<< "* Intermediary constructor testing *"
					<< std::endl ;
		ClapTrap f;
		f = a;
		std::cout 	<< "copie de a : ";
		write_clap(f);
		ClapTrap g(b);
		std::cout 	<< "copie de b : ";
		write_clap(g);
	}
	std::cout 	<< std::endl << "\033[31m*** Deconstructing ***\033[0m" 
				<< std::endl;
	return (0);
}
