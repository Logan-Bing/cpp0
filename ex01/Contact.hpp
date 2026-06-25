#include <iostream>

class Contact
{
	public:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		int			phone_number;
		int			darkest_secret;

	Contact(
			const std::string&,
			const std::string&,
			const std::string&,
			int,
			int
	);
};
