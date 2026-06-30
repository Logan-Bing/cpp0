#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void) : count (0){}

void	PhoneBook::addContact(const Contact& new_contact)
{
	if (this->count >= CONTACTS_SIZE)
	{
		for(int i = 0; i < this->count - 1; i++)
		{
			this->contacts[i] = this->contacts[i + 1];
		}
		this->count--;
	}
	this->contacts[this->count] = new_contact;
	this->count++;
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
	return index > this->count || index <= 0 ? throw std::invalid_argument("invalid_index") : this->contacts[index - 1];
}

void printField(std::ostream& os, int value)
{
	os << std::setw(10);
	os << value << '|';
}

void	printField(std::ostream&os,std::string value)
{
	if (value.length() > 10) value.replace(8, 9, 1,'.').erase(9, value.length());
	os << std::setw(10);
	os << value << '|';
}

std::ostream& operator<<(std::ostream& os, const PhoneBook& phone_book)
{
	const Contact *contacts = phone_book.getContacts();
	std::right(os);
	printField(os, "Index");
	printField(os, "Firstname");
	printField(os, "Lastname");
	printField(os, "Nickname");
	printField(os, "PhoneNum.");
	printField(os, "DarkestS.");
	os << '\n';
	for (int i = 0; i < phone_book.getCount(); i++)
	{
		printField(os, i + 1);
		printField(os, contacts[i].getFirstName());
		printField(os, contacts[i].getLastName());
		printField(os, contacts[i].getNickName());
		printField(os, contacts[i].getPhoneNumber());
		printField(os, contacts[i].getDarkestSecret());
		os << '\n';
	}
	return (os);
}
