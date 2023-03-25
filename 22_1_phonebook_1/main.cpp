#include <iostream>
#include <map>
#include <vector>
#include <string>

int main() {
	std::cout << "\tTask 22.1 PHONEBOOK\n";

	std::map<std::string, std::string> NumberToSurname;
	std::map<std::string, std::vector<std::string>> SurnameToNumber;

	std::string action;
	while (true)
	{
		std::cout << "\nEnter new phone and surname to add new \n";
		std::cout << "Enter a phone to know a surname\n";
		std::cout << "Enter a surname to know a phone\n";
		std::cout << "Enter a \"1\" to exit program\n";

		std::getline(std::cin, action);

		if (action == "1")
		{
			break;
		}
		else if (action == "")
		{
			//empty string
			continue;
		}
		else
		{
			//find the index of the first space
			int spaceIndex = action.find(" ");

			if (spaceIndex != std::string::npos)
			{
				std::string number = action.substr(0, spaceIndex);

				int nextIndex = action.find_first_not_of(" ", spaceIndex + 1);
				std::string surname = action.substr(nextIndex);

				auto it = SurnameToNumber.find(surname);

				if (it == SurnameToNumber.end())
				{
					SurnameToNumber.insert(std::make_pair(surname, std::vector<std::string>(1, number)));
					NumberToSurname.insert(std::make_pair(number, surname));
				}
				else
				{
					it->second.push_back(number);
					NumberToSurname.insert(std::make_pair(number, surname));
				}

				std::cout << "New subscriber added\n";
			}
			else
			{
				if (action[0] >= '0' && action[0] <= '9')
				{
					//it's a phone. I need a find surname

					auto it = NumberToSurname.find(action);

					if (it == NumberToSurname.end())
					{
						std::cout << "This number is not in the phonebook.\n";
					}
					else
					{
						std::cout << "Surname of the owner of the number - " << it->second << ".\n";
					}
				}
				else
				{
					auto it = SurnameToNumber.find(action);

					if (it == SurnameToNumber.end())
					{
						std::cout << "This name is not in the telephone directory.\n";
					}
					else
					{
						std::cout << "Phone numbers with this surname: ";
						for (const auto& phone : it->second)
						{
							std::cout << phone << " ";
						}
						std::cout << "\n";
					}
				}
			}

		}
	};

	return 0;
}