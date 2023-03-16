#include <iostream>
#include <map>
#include <vector>
#include <string>

int main() {
	std::cout << "\tTask 22.1 PHONEBOOK\n\n";

	std::map<std::string, std::vector<std::string>> phonebook;

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
				std::string phone = action.substr(0, spaceIndex);

				int nextIndex = action.find_first_not_of(" ", spaceIndex + 1);
				std::string surname = action.substr(nextIndex);
				
				auto it = phonebook.find(surname);

				if (it == phonebook.end())
				{
					phonebook.insert(std::make_pair(surname, std::vector<std::string>(1, phone)));
				}
				else
				{
					it->second.push_back(phone);
				}
				std::cout << "New subscriber added\n";
			}
			else
			{
				if (action[0] >= '0' && action[0] <= '9')
				{
					//it's a phone. I need a find surname

					bool isFind = false;
					for (const auto& it : phonebook)
					{
						if (isFind)
						{
							break;
						}
						for (const auto& phone : it.second)
						{
							if (phone == action)
							{
								std::cout << "Surname of the owner of the number - " << it.first << ".\n";
								isFind = true;
								break;
							}
						}
					}

					if (!isFind)
					{
						std::cout << "This number is not in the phonebook.\n";
					}

				}
				else
				{
					auto it = phonebook.find(action);

					if (it == phonebook.end())
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