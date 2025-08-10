/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/10 22:16:08 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

void	write_clap(ClapTrap & a)
{
	std::cout	<< a.get_name() << " is ClapTrap and has: " << a.get_energy_points()
				<< " Energy points, " << a.get_hit_points() << " Hit points, "
				<< a.get_attack_damage() << " attack damage" << std::endl;
	return ;
}

void	write_scav(ScavTrap & a)
{
	std::cout	<< a.get_name() << " is ScavTrap and has: " << a.get_energy_points()
				<< " Energy points, " << a.get_hit_points() << " Hit points, "
				<< a.get_attack_damage() << " attack damage" << std::endl;
	return ;
}

void	write_frag(FragTrap & a)
{
	std::cout	<< a.get_name() << " is FragTrap and has: " << a.get_energy_points()
				<< " Energy points, " << a.get_hit_points() << " Hit points, "
				<< a.get_attack_damage() << " attack damage" << std::endl;
	return ;
}

void	write_diam(DiamondTrap & a)
{
	std::cout	<< a.get_name() << " is DiamondTrap and has: " << a.get_energy_points()
				<< " Energy points, " << a.get_hit_points() << " Hit points, "
				<< a.get_attack_damage() << " attack damage" << std::endl;
	return ;
}

int		main(void)
{
	std::cout << "\033[34m*** Constructing ***\033[0m" << std::endl << std::endl;
	ClapTrap	a("One");
	write_clap	(a);
	ScavTrap	b("Two");
	write_scav	(b);
	ScavTrap	c("Three");
	write_scav	(c);
	FragTrap	d("Four");
	write_frag	(d);
	FragTrap	e("Five");
	write_frag	(e);
	DiamondTrap	h("SixSixSix");
	write_diam (h);

std::cout 	<< std::endl << "*** Testing member functions ***" 
				<< std::endl;
	std::cout << std::endl << "** ClapTrap **" << std::endl;
	a.attack("some other ClapTrap");
	a.takeDamage(5);
	a.beRepaired(3);
	a.beRepaired(5);
	a.takeDamage(100);
	a.attack("some other other ClapTrap");
	a.beRepaired(50);
	{
		std::cout 	<< std::endl << "* Intermediary ClapTrap constructor testing *"
					<< std::endl;
		ClapTrap f;
		f = a;
		std::cout << "assignation de a : ";
		write_clap(f);
		ClapTrap g(a);
		std::cout << "copie de a : ";
		write_clap(g);
	}
	std::cout << std::endl << "** ScavTrap **" << std::endl;
	b.beRepaired(30);
	b.guardGate();
	for (int i = 0; i < 52; i++)
		b.attack("everyone");
	b.guardGate();
	b.beRepaired(100);
	b.takeDamage(100);
	b.guardGate();
	c.takeDamage(100);
	c.guardGate();
	{
		std::cout 	<< std::endl << "* Intermediary ScavTrap constructor testing *"
					<< std::endl;
		ScavTrap	f;
		f = b;
		std::cout << "assignation de b : ";
		write_scav(f);
		ScavTrap g(c);
		std::cout << "copie de c : ";
		write_scav(g);
	}
	std::cout << std::endl << "** FragTrap **" << std::endl;
	d.highFivesGuys();
	for (int i = 0; i < 102; i++)
		d.attack("those who don't give him fives back");
	d.highFivesGuys();
	d.takeDamage(99);
	d.beRepaired(49);
	d.highFivesGuys();
	d.takeDamage(3000);
	d.highFivesGuys();
	e.highFivesGuys();
	e.takeDamage(30);
	e.beRepaired(50);
	e.takeDamage(-1000);
	e.highFivesGuys();
	{
		std::cout 	<< std::endl << "* Intermediary FragTrap constructor testing *"
					<< std::endl;
		FragTrap	f;
		f = d;
		std::cout << "assignation de d : ";
		write_frag(f);
		FragTrap g(e);
		std::cout << "copie de e : ";
		write_frag(g);
	}
	std::cout << std::endl << "** DiamondTrap **" << std::endl;
	h.whoAmI();
	h.highFivesGuys();
	h.takeDamage(60);
	h.guardGate();
	for (int i = 0; i < 10; i++)
		h.attack("those who have to be kicked out");
		h.guardGate();
	for (int i = 0; i < 10; i++)
		h.beRepaired(1);
	h.highFivesGuys();
	h.highFivesGuys();
	h.takeDamage(75);
	{
		std::cout 	<< std::endl << "* Intermediary DiamondTrap constructor testing *"
					<< std::endl;
		DiamondTrap	f;
		f.whoAmI();
		f = h;
		f.whoAmI();
		std::cout << "assignation de h : ";
		write_diam(f);
		DiamondTrap g(h);
		g.whoAmI();
		std::cout << "copie de h : ";
		write_diam(g);
	}
	std::cout 	<< std::endl << "\033[31m*** Deconstructing ***\033[0m"
				<< std::endl;
	return (0);
}
