#include "Contact.hpp"
#include <iostream>

Contact::Contact(
		const std::string& first_name,
		const std::string& last_name,
		const std::string& nickname,
		int phone_number, 
		int darkest_secret
)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}
