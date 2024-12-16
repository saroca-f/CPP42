/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:14:39 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/11 15:28:47 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		std::cout << RED "ERROR:" RESET " No arguments\n";
		return 1;
	}
	argv++;
	while(*argv)
	{
		try
		{
			RPN(*argv);
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << '\n';
		}
		argv++;
	}
	return 0;
}