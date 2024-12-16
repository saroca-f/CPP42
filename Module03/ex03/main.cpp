/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:38:49 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/16 11:21:42 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

void	brian_rundown(void)
{
	DiamondTrap brian("Brian");

	brian.guardGate();
	brian.highFivesGuys();
	brian.whoAmI();
}

void	alice_rundown(void)
{
	DiamondTrap alice("Alice");

	alice.guardGate();
	for (int i = 0; i < 51; i++)
	{
		std::cout << i << " : ";
		alice.attack("something");
	}
	alice.guardGate();
	alice.highFivesGuys();
	alice.whoAmI();
}

void	bob_rundown(void)
{
	DiamondTrap	bob("Bob");
	bob.takeDamage(100);
	bob.guardGate();
	bob.highFivesGuys();
	bob.whoAmI();
}

int	main(void)
{
	std::cout << std::endl << std::endl << "No problem: Performing Brian's rundown..." << std::endl << std::endl;
	brian_rundown();
	std::cout << std::endl << std::endl << "Without EN: Performing Alice's rundown..." << std::endl << std::endl;
	alice_rundown();
	std::cout << std::endl << std::endl << "Without HP: Performing Bob's rundown..." << std::endl << std::endl;
	bob_rundown();
}