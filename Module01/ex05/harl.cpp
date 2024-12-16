/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:11:53 by saroca-f          #+#    #+#             */
/*   Updated: 2024/08/15 15:47:47 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "harl.hpp"

// void    (harl::*ptr_level[4])(void) = {&harl::debug, &harl::info, &harl::warning, &harl::error};
// This function declarates a pointer to a member function of the class harl that returns void and has no parameters.

void	harl::complain( std::string level )
{
    void    (harl::*ptr_level[4])(void) = {&harl::debug, &harl::info, &harl::warning, &harl::error};
    std::string options[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (options[i] == level)
            (this->*ptr_level[i])();
    }
}

void	harl::debug( void )
{
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money.";
	std::cout << " You don’t put enough! If you did I would not have to ask";
	std::cout << " for it!" << std::endl << std::endl;
}

void	harl::info( void )
{
    std::cout << GRAY << "[INFO]" << DEFAULT << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money.";
	std::cout << " You don’t put enough! If you did I would not have to ask";
	std::cout << " for it!" << std::endl << std::endl;
}

void	harl::warning( void )
{
    std::cout << YELLOW << "[WARNING]" << DEFAULT << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming here for years and you just started ";
	std::cout << "working here last month." << std::endl << std::endl;
}

void	harl::error( void )
{
    std::cout << RED << "[ERROR]" << DEFAULT << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now.";
	std::cout << std::endl << std::endl;
}
