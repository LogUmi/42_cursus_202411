/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/09 21:18:16 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"


int	main(void)
{
	std::cout << "\033[34mConstructing\033[0m" << std::endl << std::endl;
	ClapTrap a("One");
	ClapTrap b("Two");
	{
		ClapTrap c;
		c = a;
		ClapTrap d(b);
	}
	std::cout << std::endl << "Testing" << std::endl << std::endl;
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
	std::cout << std::endl << "\033[31mDeconstructing\033[0m" << std::endl;
	return (0);
}
