#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Interface.hpp"
#include "header.h"

Interface::Interface(){}

void	Interface::seed()
{
	this->phonebook.addContact(Contact("first", "Doe", "JD", "1", "2608"));
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "2", "2608"));
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "3", "2608"));
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "4", "2608"));
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "5", "2608"));
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "6", "2608"));
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "7", "2608"));
	this->phonebook.addContact(Contact("last", "Doe", "JD", "8", "2608"));
}

std::string	askForInput(const std::string& prompt, std::string& value)
{
	std::cout << prompt;
	std::getline(std::cin, value);
	std::cin.exceptions(std::ios::eofbit);
	if (std::cin.fail()) throw std::invalid_argument("invalid_argument");
	return (value);
}

void	Interface::monitor()
{
	std::cout << "Available command [ADD] [SEARCH] [EXIT]" << '\n';
	while (this->user_input != "EXIT")
	{
		try
		{
			askForInput("> ", this->user_input);
			if (this->user_input == "ADD")	this->handleAddCmd();
			if (this->user_input == "SEARCH") this->handleSearchCmd();
		}
		catch (const std::invalid_argument& error)
		{
			std::cout << error.what() << '\n';
			std::cin.clear();
		}
		catch(const std::exception& ex)
		{
			std::cout << '\n' << "Exit" << '\n';
			break;
		}
	}
}

void	Interface::handleAddCmd()
{
	this->phonebook.addContact(createContact());
}

void	Interface::handleSearchCmd()
{
	if (this->phonebook.getCount() <= 0)
	{
		std::cout << "The phonebook is empty, use ADD cmd for add a new one" << '\n';
		return; 
	} 

	std::cout << this->phonebook;
	this->askForContactIndex();
}

void	Interface::askForContactIndex()
{
	std::string str;
	int	index;
	try 
	{
		askForInput("Type index Contact: ", str);
		std::istringstream(str) >> index;
		std::cout << this->phonebook.findByIndex(index);
	}
	catch (const std::invalid_argument & error) 
	{
		std::cout << error.what() << '\n';
	};
}

Contact	Interface::createContact()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
	Contact c;

	askForInput("Firstname: ", first_name);
	askForInput("Last_name: ", last_name);
	askForInput("Nickname: ", nickname);
	askForInput("PhoneNumber: ", phone_number);
	askForInput("DarkestSecret: ", darkest_secret);

	c = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	return c;
}
