/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 13:06:59 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/15 16:09:27 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	/* 
	tmp = src->createMateria("fire"); // should return nullptr
	if (!tmp)
		std::cout << "Tried to create unknown materia 'fire': returned nullptr ✅" << std::endl;

	std::cout << "\n===== Using Materias =====" << std::endl;
	me->use(0, *bob); // should use ice
	me->use(1, *bob); // should use cure
	me->use(2, *bob); // invalid index

	std::cout << "\n===== Unequip and Use Again =====" << std::endl;
	me->unequip(0); // should not delete materia, just unequip
	me->use(0, *bob); // should do nothing

	std::cout << "\n===== Test Deep Copy =====" << std::endl;
	Character* copy = new Character(*(dynamic_cast<Character*>(me))); // copy constructor
	std::cout << *copy;

	std::cout << "\n===== Cleanup =====" << std::endl;
	delete copy; */
	delete bob;
	delete me;
	delete src;
	return (0);
}