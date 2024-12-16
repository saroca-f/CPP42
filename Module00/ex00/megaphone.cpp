/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 12:06:11 by saroca-f          #+#    #+#             */
/*   Updated: 2024/08/05 16:44:53 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

//If no arguments: "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
//If arguments: print the arguments in uppercase
//Toupper() function converts a lowercase character to uppercase, needs a character as argument
//Thas is the reason why we need to iterate over the string

int	main(int argc, char **argv)
{
	(void)	argv;
	if(argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for(int i = 1; i < argc; i++)
		{
			for(int j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
		}
		std::cout << std::endl;
	}
}
