/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:38:49 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/16 11:19:50 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


void	bob_rundown(void)
{
	ScavTrap	bob("Bob");
	bob.guardGate();
	bob.attack("a tree");
	bob.guardGate();
	bob.attack("a tree");
}

int	main(void)
{
	std::cout << std::endl << std::endl << "Performing Bob's rundown..." << std::endl << std::endl;
	bob_rundown();
}