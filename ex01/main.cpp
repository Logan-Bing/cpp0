#include <iostream>
#include <stdexcept>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	try {
		Contact c("", "", "a", "ewq", "ewqewq");
	} catch (std::invalid_argument& e) {
		std::cerr << e.what();
	}

	return (0);
}
