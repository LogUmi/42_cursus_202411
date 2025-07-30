/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:49:06 by lgerard           #+#    #+#             */
/*   Updated: 2025/07/30 12:24:19 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	public :
		Contact(void);
		~Contact(void);

		std::string	get_first_name(int way) const;
		std::string	get_last_name(int way) const;
		std::string	get_nickname(int way) const;
		std::string	get_phone_number(int way) const;
		std::string	get_darkest_secret(int way) const;
		void		set_first_name(std::string str);
		void		set_last_name(std::string str);
		void		set_nickname(std::string str);
		void		set_phone_number(std::string str);
		void		set_darkest_secret(std::string str);

	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;

		std::string	_string_way(std::string str, int way) const;
};

#endif