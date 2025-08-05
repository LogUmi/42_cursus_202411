/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 17:12:01 by lgerard           #+#    #+#             */
/*   Updated: 2025/08/05 18:38:22 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main( int argc, char** argv )
{
	std::ifstream			ifs;
	std::ofstream			ofs;
	std::string				result;
	std::string				str;
	std::string::size_type	pos = 0;
	std::string::size_type	found = 0;
	
	if (argc != 4 )
	{
		std::cerr 	<< "ERROR: 3 arguments needed: <filename> "
					<<"<string to replace> <replacement string>"
					<< std::endl;
		return (1);
	}
	std::string	file = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (file.empty() || s1.empty() || s2.empty())
	{
		std::cerr 	<< "ERROR: empty argument(s)" 
					<< std::endl;
		return (1);
	}
	ifs.open( argv[1], std::ios::in );
	if (!ifs.is_open())
	{
		std::cerr 	<< "ERROR: file " << argv[1] << " can't be opened" 
					<< std::endl;
		return (1);
	}
	while (std::getline( ifs, result ))
	{
		str = str + result;
		if (ifs.eof() && !ifs.fail())
		{
			str = str + '\n';
			break ;
		}
		else if (ifs.eof() && ifs.fail())
			break ;
		else if (ifs.fail())
		{
			std::cerr 	<< "ERROR: Logical error : failed to read (FAIL)."
						<< " May be wrong format." << std::endl;
			return (1);
		}
		else if (ifs.bad())
		{	
			std::cerr 	<< "ERROR: Stream fatal error (BAD)!" << std::endl;
			return (1);	
		}
		str = str + '\n';
	}
	ifs.close();
	result.clear();
	while ((found = str.find(s1, pos)) != std::string::npos)
	{
		result = result + str.substr( pos, found - pos) + s2;
		pos = found + s1.size();
	}
	result = result + str.substr(pos, str.size());
	file = file + std::string(".replace");
	ofs.open( file.c_str(), std::ios::trunc );
	if (!ofs.is_open())
	{
		std::cerr 	<< "ERROR: file " << argv[1] << " can't be opened" 
					<< std::endl;
		return (1);
	}
	ofs << result;
	ofs.close();
	std::cout << "Operation done. file " << file << " saved." << std::endl;
	return (0);
}
