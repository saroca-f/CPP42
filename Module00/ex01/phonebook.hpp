/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 12:50:07 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 08:32:26 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "contact.hpp"

#define DEBUG 1

class PhoneBook
{
	private:

		Contact	_contacts[8];
		int		_size;

	public:

		void	init();
		int		get_size();
		void	add_contact();
		void	when_full_contacts();
		void	search_contact();
};

int		number_control(std::string str, int flag);

#endif