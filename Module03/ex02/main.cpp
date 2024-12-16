/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:38:49 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/14 12:35:23 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


void	bob_rundown(void)
{
	FragTrap	bob("Bob");
	bob.highFivesGuys();
	bob.takeDamage(100);
	bob.highFivesGuys();
}

int	main(void)
{
	std::cout << std::endl << std::endl << "Performing Bob's rundown..." << std::endl << std::endl;
	bob_rundown();
}