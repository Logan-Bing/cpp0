#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "Interface.hpp"
#include "header.h"

Interface::Interface(){}

void	Interface::seed()
{
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "1", "2608"));
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "2", "2608"));
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "3", "2608"));
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "4", "2608"));
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "5", "2608"));
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "6", "2608"));
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "7", "2608"));
	this->phonebook.addContact(Contact("jhon", "Doe", "JD", "8", "2608"));
}

template <typename T>
T	askForInput(const std::string& prompt)
{
	T value;
	std::cout << prompt;
	std::cin >> value;
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
			this->user_input = askForInput<std::string>("> ");

			if (this->user_input == "ADD")	this->handleAddCmd();
			if (this->user_input == "SEARCH") this->handleSearchCmd();
		}
		catch (const std::invalid_argument& error)
		{
			std::cout << error.what() << '\n';
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
	std::cout << this->phonebook;
	this->askForContactIndex();
}

void	Interface::askForContactIndex()
{
	int index = askForInput<int>("Type index Contact: ");
	std::cout << this->phonebook.findByIndex(index);
}

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
