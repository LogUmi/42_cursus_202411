#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc > 1)
		std::cout << "Arguments are ignored" << std::endl;
	std::cout << "Welcome in My Awesome PhoneBook !" << std::endl;
	std::cout << "Please type a command ADD, SEARCH or EXIT : " << std::endl;

	
	return (0);
}