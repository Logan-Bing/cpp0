#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "header.h"

class Interface
{
	private:
		std::string	user_input;
		PhoneBook	phonebook;

	public:
		Interface(void);
		void	seed();
		void	monitor();
		void	askForContactArg(std::string&, const char *);
		void	askForContactIndex();
		void	handleAddCmd();
		void	handleSearchCmd();
		Contact	createContact();
};

#endif
