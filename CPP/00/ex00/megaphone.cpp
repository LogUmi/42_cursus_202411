#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{	
		int i = 1;
		//int j = 0;
		while (i < (argc))
		{
			if (i > 1)
				std::cout << " ";
			std::string chr = argv[i++];
			/* if (chr.size() == 0)
				std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *"; */
			else
			{
				std::cout << chr;
				/* j = 0;
					while (!chr.empty())
					std::cout << ::toupper(chr[j++]); */
			}
		}
		std::cout << std::endl;
	}
	return (0);
}