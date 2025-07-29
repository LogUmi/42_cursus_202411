/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:50:09 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/29 18:35:04 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

# ifndef MAX_RECORD
#  define MAX_RECORD 8
# endif

class PhoneBook
{
	public:

		PhoneBook(void);
		~PhoneBook(void);

		void	add_request(void);
		void	search(void);

	private:
		Contact	_record[MAX_RECORD];
		int		_older;
		int		_count;

		void 	_add_record(int n, std::string* tab);
};

#endif