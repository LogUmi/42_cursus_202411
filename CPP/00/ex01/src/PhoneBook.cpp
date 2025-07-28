#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : older(-1), count(0)
{
	std::cout << "PhoneBook constructor called." << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called." << std::endl;
}