/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:35:34 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 08:29:54 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int number_control(std::string str, int flag)
{
	int i = 0;

	if (str.length() != 9 && flag == 1)
		return 1;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return 1;
		i++;
	}
	return 0;
}

int	input_strlen(std::string str)
{
	int i = 0;

	while (str[i])
		i++;
	return i;
}

void	Contact::add_first_name(std::string str)
{
	this->_first_name = str;
}

void	Contact::add_last_name(std::string str)
{
	this->_last_name = str;
}

void	Contact::add_nickname(std::string str)
{
	this->_nickname = str;
}

void	Contact::add_phone_number(std::string nbr)
{
	this->_phone_number = nbr;
}

void	Contact::add_secret(std::string str)
{
	this->_darkest_secret = str;
}

void PhoneBook::when_full_contacts()
{
	int i = 0;
	std::string	input;

	while (i < 7)
	{
		this->_contacts[i] = this->_contacts[i + 1];
		i++;
	}
	std::cout << "\nInsert first name\n> ";
	if (!std::getline(std::cin, input, '\n'))
		return ;
	while (input[0] == '\0')
	{
		if (input[0] == '\0')
			std::cout << "ERROR: NO NAME\n";
		std::cout << "Insert first name\n> ";
		if (!std::getline(std::cin, input, '\n'))
			return ;
	}
	this->_contacts[this->_size - 1].add_first_name(input);
	std::cout << "\nInsert last name\n> ";
	if (!std::getline(std::cin, input, '\n'))
		return ;
	while (input[0] == '\0')
	{
		if (input[0] == '\0')
			std::cout << "ERROR: NO LAST NAME\n";
		std::cout << "Insert last name\n> ";
		if (!std::getline(std::cin, input, '\n'))
			return ;
	}
	this->_contacts[this->_size - 1].add_last_name(input);
	std::cout << "\nInsert nickname\n> ";
	if (!std::getline(std::cin, input, '\n'))
		return ;
	while (input[0] == '\0')
	{
		if (input[0] == '\0')
			std::cout << "ERROR: NO NICKNAME\n";
		std::cout << "Insert nickname\n> ";
		if (!std::getline(std::cin, input, '\n'))
			return ;
	}
	this->_contacts[this->_size - 1].add_nickname(input);
	std::cout << "\nInsert phone number\n> ";
	if (!std::getline(std::cin, input, '\n'))
		return ;
	while (number_control(input, 1))
	{
		if (input.length() < 9)
			std::cout << "ERROR: PHONE NUMBER TO SHORT\n";
		else if (input.length() > 9)
			std::cout << "ERROR: PHONE NUMBER TOO LONG\n";
		else
			std::cout << "ERROR: PHONE NUMBER CONTAINS NON DIGITS\n";
		std::cout << "Insert phone number with 9 numbers\n> ";
		if (!std::getline(std::cin, input, '\n'))
			return ;
	}
	this->_contacts[this->_size - 1].add_phone_number(input);
	std::cout << "\nInsert a secret\n> ";
	if (!std::getline(std::cin, input, '\n'))
		return ;
	while (input[0] == '\0')
	{
		if (input[0] == '\0')
			std::cout << "ERROR: NO SECRET\n";
		std::cout << "\nInsert a secret\n> ";
		if (!std::getline(std::cin, input, '\n'))
			return ;
	}
	this->_contacts[this->_size - 1].add_secret(input);
}

void PhoneBook::add_contact()
{
	std::string	input;

	if (this->_size == 8)
	{
		std::cout << "WARNING! PHONEBOOK IS FULL!\n" << std::endl;
		std::cout << "If you want to add a new contact, the oldest constact is going to be deleted" << std::endl;
		std::cout << "Do you want to continue? (y/n)" << std::endl << "> ";
		if (!std::getline(std::cin, input, '\n'))
			return ;
		while (input[0] != 'y' && input[0] != 'n')
		{
			std::cout << "ERROR: INVALID INPUT\n";
			std::cout << "Do you want to continue? (y/n)" << std::endl << "> ";
			if (!std::getline(std::cin, input, '\n'))
				return ;
		}
		if (input[0] == 'y')
			this->when_full_contacts();
		return ;
	}
	std::cout << "\nInsert first name\n> ";
	if (!std::getline(std::cin, input, '\n'))
		return ;
	while (input[0] == '\0')
	{
		if (input[0] == '\0')
			std::cout << "ERROR: NO NAME\n";
		std::cout << "Insert first name\n> ";
		if (!std::getline(std::cin, input, '\n'))
			return ;
	}
	this->_contacts[this->_size].add_first_name(input);
	std::cout << "\nInsert last name\n> ";
	if (!std::getline(std::cin, input, '\n'))
		return ;
	while (input[0] == '\0')
	{
		if (input[0] == '\0')
			std::cout << "ERROR: NO LAST NAME\n";
		std::cout << "Insert last name\n> ";
		if (!std::getline(std::cin, input, '\n'))
			return ;
	}
	this->_contacts[this->_size].add_last_name(input);
	std::cout << "\nInsert nickname\n> ";
	if (!std::getline(std::cin, input, '\n'))
		return ;
	while (input[0] == '\0')
	{
		if (input[0] == '\0')
			std::cout << "ERROR: NO NICKNAME\n";
		std::cout << "Insert nickname\n> ";
		if (!std::getline(std::cin, input, '\n'))
			return ;
	}
	this->_contacts[this->_size].add_nickname(input);
	std::cout << "\nInsert phone number\n> ";
	if (!std::getline(std::cin, input, '\n'))
		return ;
	while (number_control(input, 1))
	{
		if (input.length() < 9)
			std::cout << "ERROR: PHONE NUMBER TO SHORT\n";
		else if (input.length() > 9)
			std::cout << "ERROR: PHONE NUMBER TOO LONG\n";
		else
			std::cout << "ERROR: PHONE NUMBER CONTAINS NON DIGITS\n";
		std::cout << "Insert phone number with 9 numbers\n> ";
		if (!std::getline(std::cin, input, '\n'))
			return ;
	}
	this->_contacts[this->_size].add_phone_number(input);
	std::cout << "\nInsert a secret\n> ";
	if (!std::getline(std::cin, input, '\n'))
		return ;
	while (input[0] == '\0')
	{
		if (input[0] == '\0')
			std::cout << "ERROR: NO SECRET\n";
		std::cout << "\nInsert a secret\n> ";
		if (!std::getline(std::cin, input, '\n'))
			return ;
	}
	this->_contacts[this->_size].add_secret(input);
	this->_size++;
}
