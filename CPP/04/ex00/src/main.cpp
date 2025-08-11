/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 21:46:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/12 00:28:02 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
//#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
//#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound(); // dog sound
meta->makeSound();


std::cout 	<< std::endl << "\033[033m* complementary constructor tests *\033[0m" 
			<< std::endl;
Animal * a = new Dog(*(Dog*)j);
std::cout << "Type = " << a->getType() << " " << std::endl;
a->makeSound();
Dog b = *(Dog*)j;
std::cout << "New " << b.getName() << "Type = " << b.getType() << " " << std::endl;
b.makeSound();
Dog c = b;
std::cout << "New " << c.getName() << "Type = " << c.getType() << " " << std::endl;
c.makeSound();

std::cout 	<< std::endl << "\033[033m* WrongAnimal tests *\033[0m" 
				<< std::endl;
const WrongAnimal* k = new WrongCat();
std::cout << k->getType() << " " << std::endl;
k->makeSound(); //will output the WrongAnimal sound!

delete k;
delete a;
delete i;
delete j;
delete meta;
return (0) ;
}