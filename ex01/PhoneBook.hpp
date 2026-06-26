#ifndef	PHONEBOOK_HPP 
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "header.h"

#define CONTACTS_SIZE 8

class PhoneBook
{
	private:
		Contact contacts[CONTACTS_SIZE];
		int count;

	public:
		PhoneBook(void);
		void	addContact(const Contact&);
		const Contact& findByIndex(int index);
		const Contact* getContacts() const;
		int	getCount() const;
};

std::ostream& operator<<(std::ostream& os, const PhoneBook&);

#endif
