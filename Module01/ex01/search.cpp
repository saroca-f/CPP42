/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:46:24 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 08:30:48 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Contact::print_first_name_contact()
{
	std::string str = this->_first_name;
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	std::cout << std::setw(10) << str << "|";
}

void	Contact::print_last_name_contact()
{
	std::string str = this->_last_name;
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	std::cout << std::setw(10) << str << "|";
}

void	Contact::print_nickname_contact()
{
	std::string str = this->_nickname;
	if (str.length() > 10)
	{
		str.resize(9);
		str.append(".");
	}
	std::cout << std::setw(10) << str << "|";
}

void	Contact::print_phone_number_contact()
{
	std::cout << std::setw(10) << this->_phone_number << "|";
}

void	Contact::print_secret_contact()
{
	std::string str = this->_darkest_secret;
	if (str.length() > 43)
	{
		str.resize(42);
		str.append(".");
	}
	std::cout << std::endl << "|                                           |";
	std::cout << std::endl << "|DARKEST SECRET                             |";
	std::cout << std::endl << "|___________________________________________|";
	std::cout << std::endl << "|                                           |";
	std::cout << std::endl << "|" << std::setw(43) << str << "|";
	std::cout << std::endl << "|___________________________________________|";

}



void	Contact::print_contact()
{
	std::cout << " ___________________________________________\n";
	std::cout << "|          |          |          |          |\n";
	std::cout << "|NAME      |LAST NAME |NICKNAME  |P.NUMBER  |\n";
	std::cout << "|__________|__________|__________|__________|\n";
	std::cout << "|          |          |          |          |\n|";
	this->print_first_name_contact();
	this->print_last_name_contact();
	this->print_nickname_contact();
	this->print_phone_number_contact();
	std::cout << std::endl << "|__________|__________|__________|__________|";
	this->print_secret_contact();
	std::cout << std::endl << std::endl;
}

void	PhoneBook::search_contact()
{
	int i;
	int j;
	std::string input;

	i = 0;
	j = -1;
	if(this->_size == 0)
	{
		std::cout << "No contacts to search for." << std::endl;
		return ;
	}
	std::cout << " ___________________________________________\n";
	std::cout << "|          |          |          |          |\n";
	std::cout << "|     INDEX|      NAME| LAST NAME|  NICKNAME|\n";
	std::cout << "|__________|__________|__________|__________|\n";
	while(i < this->_size)
	{
		std::cout << "|          |          |          |          |\n";
		std::cout << "|         " << i + 1 << "|";
		this->_contacts[i].print_first_name_contact();
		this->_contacts[i].print_last_name_contact();
		this->_contacts[i].print_nickname_contact();
		std::cout << std::endl;
		std::cout << "|__________|__________|__________|__________|\n";
		i++;
	}
	std::cout << "Enter the index of the contact you want to display or REGRET to return:\n";
	if (!std::getline(std::cin, input))
		return;
	if (input == "REGRET")
		return;
	j = std::atoi(input.c_str());
	while(j <= 0 || j > this->_size || number_control(input, 0))
	{
		std::cout << "Invalid option. Please select another one.\n";
		j = -1;
		if (!std::getline(std::cin, input))
			return;
		if (input == "REGRET")
			return;
		j = std::atoi(input.c_str());
	}
	this->_contacts[j - 1].print_contact();
}