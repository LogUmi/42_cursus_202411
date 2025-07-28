#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{	
		int i = 1;
		unsigned long j = 0;
		while (i < (argc))
		{
			std::string chr = argv[i++];
			j = 0;
			while (j < chr.size())
			{
				chr[j] = std::toupper(chr[j]);
				j++;
			}
			std::cout << chr;
		}
		std::cout << std::endl;
	}
	return (0);
}