#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		Contact	record[8];

		PhoneBook(void);
		~PhoneBook(void);

	private:
		int	older;
		int	count;
};

#endif