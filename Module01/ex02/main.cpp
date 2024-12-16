/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 16:39:59 by saroca-f          #+#    #+#             */
/*   Updated: 2024/08/13 11:31:29 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void )
{
	std::string		string = "HI THIS IS BRAIN";
	// Pointer to string
	// If you do not use &string, you will get a compilation error
	// Because the pointer is not of the same type as the variable
	std::string		*stringPTR = &string;
	// Reference to string
	// This variable is declarated as a reference to a string at the beginning
	std::string		&stringREF = string;

	std::cout << "memory string:\t\t" << &string << std::endl;
	std::cout << "memory stringPTR:\t" << stringPTR << std::endl;
	std::cout << "memory stringREF:\t" << &stringREF << std::endl;

	std::cout << "value string:\t\t" << string << std::endl;
	std::cout << "value stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "value stringREF:\t" << stringREF << std::endl << std::endl;

	stringREF = "THIS IS BRAIN AGAIN"; // REFERENCE CHANGES THE VALUE OF THE VARIABLE

	std::cout << "memory string:\t\t" << &string << std::endl;
	std::cout << "memory stringPTR:\t" << stringPTR << std::endl;
	std::cout << "memory stringREF:\t" << &stringREF << std::endl;

	std::cout << "value string:\t\t" << string << std::endl;
	std::cout << "value stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "value stringREF:\t" << stringREF << std::endl << std::endl;

	*stringPTR = "BYE THIS IS BRAIN"; // POINTER CHANGES THE VALUE OF THE VARIABLE

	std::cout << "memory string:\t\t" << &string << std::endl;
	std::cout << "memory stringPTR:\t" << stringPTR << std::endl;
	std::cout << "memory stringREF:\t" << &stringREF << std::endl;

	std::cout << "value string:\t\t" << string << std::endl;
	std::cout << "value stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "value stringREF:\t" << stringREF << std::endl;

	return 0;
}
