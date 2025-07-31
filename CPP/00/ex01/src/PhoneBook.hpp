/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:50:09 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/31 12:43:55 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# ifndef MAX_RECORD
#  define MAX_RECORD 8
# endif

# ifndef MAX_CHAR_NAMES
#  define MAX_CHAR_NAMES 32
# endif

# ifndef MAX_PHONE_NBR
#  define MAX_PHONE_NBR 12
# endif

# ifndef MAX_CHAR_SECRET
#  define MAX_CHAR_SECRET 256
# endif

class PhoneBook
{
	public:

		PhoneBook( void );
		~PhoneBook( void );

		void	add_request( void );
		void	search( void ) const;

	private:
		Contact	_record[MAX_RECORD];
		int		_older;
		int		_count;

		void 	_add_record( int n, std::string* tab );
		int		_get_record( std::string *tab ) const;
};

#endif