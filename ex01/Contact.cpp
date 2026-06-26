#include "Contact.hpp"
#include "header.h"

Contact::Contact(
		const std::string& first_name,
		const std::string& last_name,
		const std::string& nickname,
		const std::string& phone_number,
		const std::string& darkest_secret
)
{
	isValidInput(first_name) ? this->first_name = first_name : throw std::invalid_argument("invalid_argument (first_name)");
	isValidInput(last_name) ? this->last_name = last_name: throw std::invalid_argument("invalid_argument (last_name)");
	isValidInput(nickname) ? this->nickname = nickname : throw std::invalid_argument("invalid_argument (nickname)");
	isValidInput(phone_number) ? this->phone_number = phone_number : throw std::invalid_argument("invalid_argument (phone_number)");
	isValidInput(darkest_secret) ? this->darkest_secret = darkest_secret : throw std::invalid_argument("invalid_argument (darkest_secret)");
}

Contact::Contact(void)
{
}

const std::string&	Contact::getFirstName(void) const
{
	return (this->first_name);
}

const std::string&	Contact::getLastName(void) const
{
	return (this->last_name);
}

const std::string&	Contact::getNickName(void) const
{
	return (this->nickname);
}

const std::string&	Contact::getPhoneNumber(void) const
{
	return (this->phone_number);
}

const std::string&	Contact::getDarkestSecret(void) const
{
	return (this->darkest_secret);
}

bool	Contact::isValidInput(const std::string& input)
{
	return input.empty() ? false : true;
}

std::ostream& operator<<(std::ostream& os, const Contact& c)
{
	std::left(os);
	os << std::setw(20);	
	os << "Firstname: " << c.getFirstName() << '\n';
	os << std::setw(20);	
	os << "Lastname: " << c.getLastName() << '\n';
	os << std::setw(20);	
	os << "Nickname: " << c.getNickName() << '\n';
	os << std::setw(20);	
	os << "Phonenumber: " << c.getPhoneNumber() << '\n';
	os << std::setw(20);	
	os << "DarkestSecret: " << c.getDarkestSecret() << '\n';
	return (os);
}
