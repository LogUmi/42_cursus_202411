/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:49:56 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/29 17:52:53 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	main(int argc, char **argv)
{
	PhoneBook	pb;
	std::string	cmd;
	
	(void)argv;
	if (argc > 1)
		std::cout << "Arguments are ignored" << std::endl;
	std::cout << "Welcome in My Awesome PhoneBook !" << std::endl;
	while (true)
	{
		std::cout << "Please type a command ADD, SEARCH or EXIT: ";
		if (std::getline(std::cin, cmd))
		{
			if (cmd == "EXIT")
				break;
			else if (cmd == "ADD")
				pb.add_request();
			else if (cmd == "SEARCH")
				pb.search();
		}
		else if (std::cin.eof())
		{
			std::cout << "End of file reached (EOF)." << std::endl;
			break;
		}
			else if (std::cin.fail())
		{
			std::cerr << "logical error : failed to read (FAIL)." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		else if (std::cin.bad())
		{	
			std::cerr << "stream fatal error (BAD)!" << std::endl;
			break;
		}
	}
	std::cout << "See you later ... bye." << std::endl;
	return (0);
}