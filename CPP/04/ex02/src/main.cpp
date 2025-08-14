/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/13 22:18:54 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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

int main()
{
	int	i = 0;
	{
		std::cout 	<< "**********************************************"
					<< std::endl
					<< "*********    main given in subject    ********"
					<< std::endl
					<< "**********************************************"
					<< std::endl;
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}

	std::cout 	<< "\033[34m**********************************************\033[0m"
				<< std::endl
				<< "\033[34m*********  AAnimal table construction  ********\033[0m"
				<< std::endl
				<< "\033[34m**********************************************\033[0m"
				<< std::endl;
	AAnimal* tableau[10];
	for (i = 0; i < 5; i++)
	{
		tableau[i] = new Dog( "Fido" + int_to_string(i + 1));
		std::cout 	<< "\033[34m______________________________________________\033[0m" 
				<< std::endl;
	}	
	for (i = 5; i < 10; i++)
	{
		tableau[i] = new Cat( "Pussy" + int_to_string(i - 4));
		std::cout 	<< "\033[34m______________________________________________\033[0m" 
					<< std::endl;
	}
	
	std::cout 	<< "\033[31m**********************************************\033[0m"
				<< std::endl
				<< "\033[31m********* AAnimal table deconstruction ********\033[0m"
				<< std::endl
				<< "\033[31m**********************************************\033[0m"
				<< std::endl;
	for (i = 0; i < 10; i++)
	{
		delete tableau[i];
		std::cout 	<< "\033[31m______________________________________________\033[0m" 
					<< std::endl;
	}
	std::cout 	<< "\033[36m**********************************************\033[0m"
				<< std::endl
				<< "\033[36m*********   Brain and  copy testing   ********\033[0m"
				<< std::endl
				<< "\033[36m**********************************************\033[0m"
				<< std::endl;
	
	std::cout << std::endl << "\033[34m** Dog a = Dog() **\033[0m" << std::endl;
	Dog a = Dog();
	std::cout 	<< "This new born is " << a.getName() << " is an AAnimal type :" 
				<< a.getType() << std::endl;	
	a.makeSound();
	std::cout 	<< "Dog by default ";
	a.thinking();
	a.set_idea("what are you looking at ?");
	std::cout 	<< "this buddy has a new idea and now ";
	a.thinking();

	std::cout << std::endl << "\033[34m** Dog b = Dog(a) **\033[0m" << std::endl;
	Dog b = Dog(a);
	std::cout 	<< "This new born is " << b.getName() << " is an AAnimal type :" 
				<< b.getType() << std::endl;	
	b.makeSound();
	std::cout 	<< "this copy of buddy ";
	b.thinking();

	std::cout << std::endl << "\033[34m** Dog e = Dog(); e = a **\033[0m" << std::endl;
	Dog e = a;
	std::cout 	<< "This new born is " << e.getName() << " is an AAnimal type :" 
				<< e.getType() << std::endl;	
	e.makeSound();
	std::cout 	<< "this assignation of buddy ";
	e.thinking();
	

	std::cout << std::endl << "\033[34m** Cat c = Cat() **\033[0m" << std::endl;
	Cat c = Cat();
	std::cout 	<< "This new born is " << c.getName() << " is an AAnimal type :" 
				<< c.getType() << std::endl;	
	c.makeSound();
	std::cout 	<< "Cat by default ";
	c.thinking();
	c.set_idea("I can stare at you too !");
	std::cout 	<< "this kitty has a new idea and now ";
	c.thinking();
	std::cout << std::endl << "\033[34m** Cat d = Cat(c) **\033[0m" << std::endl;
	Cat d = Cat(c);
	std::cout 	<< "This new born is " << d.getName() << " is an AAnimal type :" 
				<< d.getType() << std::endl;	
	d.makeSound();
	std::cout 	<< "this copy of kitty ";
	c.thinking();

	std::cout << std::endl << "\033[34m** Cat f = Cat(); f = c **\033[0m" << std::endl;
	Dog f = a;
	std::cout 	<< "This new born is " << f.getName() << " is an AAnimal type :" 
				<< f.getType() << std::endl;	
	f.makeSound();
	std::cout 	<< "this assignation of buddy ";
	f.thinking();
	std::cout << "\033[31m** deconstruction **\033[0m" << std::endl;
return (0) ;
}