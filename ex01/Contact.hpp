#include <iostream>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

	public:
		Contact(
				const std::string&,
				const std::string&,
				const std::string&,
				const std::string&,
				const std::string&
		);
		const std::string&	getFirstName(void) const;
		const std::string&	getLastName(void) const;
		const std::string&	getNickName(void) const;
		const std::string&	getPhoneNumber(void) const;
		const std::string&	getDarkestSecret(void) const;
	
	private:
		bool	isValidInput(const std::string&);

		// bool	setFirstName(const std::string&) const;
		// bool	setLastName(const std::string&) const;
		// bool	setNickName(const std::string&) const;
		// bool	setPhoneNumber(const int) const;
		// bool	setDarkestSecret(const int) const;
};

std::ostream& operator<<(std::ostream& os, const Contact& c);
