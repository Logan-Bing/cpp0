#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Interface.hpp"

Interface::Interface(){}

void	Interface::monitor()
{
	PhoneBook phone_book;
	std::cout << "Available command [ADD] [SEARCH] [EXIT]" << '\n';
	while (this->user_input != "EXIT")
	{
		std::cout << "> ";
		std::cin >> this->user_input;
		if (this->user_input == "ADD")
		{
			phone_book.addContact(createContact());
		}
		else if (this->user_input == "SEARCH")
		{
			std::cout << phone_book;
			int index;
			std::cout << "Type index Contact: ";
			std::cin >> index;
			std::cout << phone_book.findByIndex(index);
		}
	}
}

// void	Interface::askForContactIndex()
// {
// 	int index;
// 	std::cout << "Type index Contact: ";
// 	std::cin >> index;
// }

void	Interface::askForContactArg(std::string& attr, const char *label)
{
	std::cout << label << ": "; 
	std::cin >> attr;
	Contact::isValidInput(attr);
}

Contact	Interface::createContact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	try
	{
		this->askForContactArg(first_name, "Firstname");
		this->askForContactArg(last_name, "Lastname");
		this->askForContactArg(nickname, "Nickname");
		this->askForContactArg(phone_number, "Phone number");
		this->askForContactArg(darkest_secret, "Darkest secret");
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}

	Contact c(first_name, last_name, nickname, phone_number, darkest_secret);
	return c;
}
