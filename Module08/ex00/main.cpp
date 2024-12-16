/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:55:54 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/29 12:23:48 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main (void)
{
	std::cout << YELLOW "\n---------------\n";
	std::cout << "||VECTOR TEST||\n";
	std::cout << "---------------\n\n" RESET;
	{
		std::vector<int> container;
		container.push_back(55);
		container.push_back(8);
		container.push_back(3);
		container.push_back(74);
		if (easyfind(container, 8) == true)
			std::cout << GREEN "Container contains that Int\n" RESET;
		else
			std::cout << RED "Container not contains that Int\n" RESET;
		if (easyfind(container, 9) == true)
			std::cout << GREEN "Container contains that Int\n" RESET;
		else
			std::cout << RED "Container not contains that Int\n" RESET;
	}
	std::cout << YELLOW "\n-------------\n";
	std::cout << "||LIST TEST||\n";
	std::cout << "-------------\n\n" RESET;
	{
		std::list<int> container2;
		container2.push_back(55);
		container2.push_back(8);
		container2.push_back(3);
		container2.push_back(74);
		if (easyfind(container2, 8) == true)
			std::cout << GREEN "Container contains that Int\n" RESET;
		else
			std::cout << RED "Container not contains that Int\n" RESET;
		if (easyfind(container2, 9) == true)
			std::cout << GREEN "Container contains that Int\n" RESET;
		else
			std::cout << RED "Container not contains that Int\n" RESET;
	}
	return 0;
}