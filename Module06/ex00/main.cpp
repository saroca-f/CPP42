/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:35:25 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/22 17:41:37 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	std::cout << std::endl;
	for (int i = 1; argv[i]; i++)
	{
		std::cout << YELLOW << "[ARGV] -> " << RESET << argv[i] << std::endl;
		try {
			ScalarConverter::convert(argv[i]);}
		catch (const std::runtime_error &e){
			std::cerr << RED << "Error: " << e.what() << RESET << std::endl;}
		if ( i < argc - 1)
			std::cout << std::endl << RED << "---------------------------------------------------------------------" << std::endl << std::endl;
	}
	std::cout << std::endl;
	return (0);
}