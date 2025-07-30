/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:49:56 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/30 18:00:45 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.hpp"

int	is_name(std::string str)
{
	int	i = 0;
	int j = 0;
	while (i < str.size())
	{
		if ((str [i] >= 'a' && str[i] <='z') || (str[i] >= 'A' && str[i] <= 'Z')
			|| str[i] == ' ' || str[i] == '\'"'|| str[i] == '-')
			j++;
		i++;
	}
	return (str.size() - j);
}

int	get_int(int *input, std::string str)
{
	while (true)
	{
		std::cout << str;
		if (std::cin >> (*input))
		{
			std::cin.ignore(1000, '\n');
			return (0);
		}	else if (std::cin.eof())
		{
			std::cout << "\n[ERROR] End of file reached (EOF)." << std::endl;
			break;
		}
			else if (std::cin.fail())
		{
			std::cerr << "[ERROR] Logical error : failed to read (FAIL). May be wrong format." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			continue;
		}
		else if (std::cin.bad())
		{	
			std::cerr << "\n[ERROR] Stream fatal error (BAD)!" << std::endl;
			break;
		}
	}
	return (1);
}

int	get_str(std::string &input, std::string str)
{
	while (true)
	{
		std::cout << str;
		if (std::getline(std::cin, input))
			return (0);
		else if (std::cin.eof())
		{
			std::cout << "\n[ERROR] End of file reached (EOF)." << std::endl;
			break;
		}
			else if (std::cin.fail())
		{
			std::cerr << "[ERROR] Logical error : failed to read (FAIL). May be wrong format." << std::endl;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			continue;
		}
		else if (std::cin.bad())
		{	
			std::cerr << "\n[ERROR] Stream fatal error (BAD)!" << std::endl;
			break;
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	PhoneBook	pb;
	std::string	cmd;
	
	(void)argv;
	if (argc > 1)		std::cout << "Arguments are ignored buddy !" << std::endl;
	std::cout << "Welcome in My Awesome PhoneBook !" << std::endl;
	while (true)
	{
		if (get_str(cmd, "[INPUT] Please type a command ADD, SEARCH or EXIT: ") == 0)
		{
			if (cmd == "EXIT")
				break;
			else if (cmd == "ADD")
				pb.add_request();
			else if (cmd == "SEARCH")
				pb.search();
		}
		else
			break;
	}
	std::cout << "See you later ... bye." << std::endl;
	return (0);
}
