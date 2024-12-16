/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:38:49 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/14 12:19:50 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

void	bob_rundown(void)
{
	ClapTrap	bob("Bob");
	bob.attack("a tree");
	bob.takeDamage(5);
	bob.attack("another tree");
	bob.beRepaired(5);
	bob.attack("a third tree");
	bob.attack("a fourth tree");
	bob.attack("a fifth tree");
	bob.attack("a sixth tree");
	bob.attack("a seventh tree");
	bob.attack("an eighth tree");
	bob.attack("a ninth tree");
	bob.attack("a tenth tree");
	bob.takeDamage(10);
	bob.attack("an eleventh tree");
}

int	main(void)
{
	std::cout << std::endl << std::endl << "Without HP: Performing Bob's rundown..." << std::endl << std::endl;
	bob_rundown();
}