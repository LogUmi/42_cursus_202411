#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
 :
 first_name{""}, 
 last_name{""},
 nick_name{""},
 phone_number{""},
 darkest_secret{""}
{
	std::cout << "Contact constructor called." << std::endl;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called." << std::endl;
}