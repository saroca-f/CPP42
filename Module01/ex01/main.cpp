/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:49:51 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 08:30:01 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	PhoneBook::init()
{
	this->_size = 0;
}

int main()
{
	std::string	command;
	PhoneBook	phonebook;

	phonebook.init();
	while (command != "EXIT")
	{
		if (std::cin.fail() || std::cin.eof())
		{
			if (DEBUG)
				std::cout << "EOF\n";
			return 1;
		}
		std::cin.clear();
		std::cout << "Welcome to your phonebook. Enter a command:\t-ADD- -SEARCH- -EXIT-" << std::endl;
		if (!std::getline(std::cin, command, '\n'))
			return 1;
		if (command == "ADD")
			phonebook.add_contact();
		if (command == "SEARCH")
			phonebook.search_contact();
	}
	return 0;
}