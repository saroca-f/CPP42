/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:07:23 by saroca-f          #+#    #+#             */
/*   Updated: 2024/08/15 16:38:40 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "harl.hpp"

int	manolo_says(char *level)
{
	std::string	options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		if (options[i] == level)
			return (i);
	return (-1);
}

    // Switch calls a function that return a int that is used like a case
    // When the function return a value, it will go to the case that has the same value
    // and enter in all the cases that are below it.
    // If no return a considerated case, it will go to the default case
    // The use ok break is important to avoid the execution of the next cases, default in this case.

    // In this case, if the function manolo_says return 1 it will go to the case 1
    // and execute the manolo.complain("INFO"), manolo.complain("WARNING") and manolo.complain("ERROR")
    // because there is no break in the cases, except in the last one.
    // Thats why do not execute the default case.

void    manolo_switch(char *level, harl &manolo)
{
    switch (manolo_says(level))
	{
		case 0:
			manolo.complain("DEBUG");
		case 1:
			manolo.complain("INFO");
		case 2:
			manolo.complain("WARNING");
		case 3:
			manolo.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int main(int argc, char **argv)
{
    harl manolo;

    if (argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	else
		manolo_switch(argv[1], manolo);
	return (0);
}