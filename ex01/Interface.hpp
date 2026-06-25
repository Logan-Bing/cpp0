#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class Interface
{
	private:
		std::string	user_input;

	public:
		Interface(void);
		void	monitor();
		void	askForContactArg(std::string&, const char *);
		void	askForContactIndex();
		Contact	createContact();
};

#endif
