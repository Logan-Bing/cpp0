#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook(void) : count (0)
{
	// std::cout << "constructor PhoneBook called" << '\n';
}

void	PhoneBook::addContact(const Contact& new_contact)
{
	this->contacts[this->count] = new_contact;
	this->count >= CONTACTS_SIZE - 1 ? this->count = CONTACTS_SIZE - 1: this->count++;
}

int	PhoneBook::getCount(void) const
{
	return (this->count);
}

const Contact*	PhoneBook::getContacts(void) const
{
	return (this->contacts);
}

const Contact&	PhoneBook::findByIndex(int index)
{
	return index > this->count || index < this->count ? this->contacts[index] : throw std::invalid_argument("invalid_index");
}

std::ostream& operator<<(std::ostream& os, const PhoneBook& phone_book)
{
	const Contact *contacts = phone_book.getContacts();
	os << std::setw(10);
	os << "index" << '|';
	os << std::setw(10);
	os << "Firstname" << '|';
	os << std::setw(10);
	os << "Lastname" << '|';
	os << std::setw(10);
	os << "Nickname" << '|';
	os << std::setw(10);
	os << "PhoneNumber" << '|';
	os << std::setw(10);
	os << "DarkestSecret" << '|';
	os << '\n';
	for (int i = 0; i < phone_book.getCount(); i++)
	{
		os << std::setw(10);
		os << i << '|';
		os << std::setw(10);
		os << contacts[i].getFirstName() << '|';
		os << std::setw(10);
		os << contacts[i].getNickName() << '|';
		os << std::setw(10);
		os << contacts[i].getPhoneNumber() << '|';
		os << std::setw(10);
		os << contacts[i].getDarkestSecret() << '|';
		os << std::setw(10);
		os << contacts[i].getLastName();
		os << '\n';
	}
	return (os);
}
