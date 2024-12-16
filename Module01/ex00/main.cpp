/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:42:53 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 08:53:01 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	//Call to the function newZombie to create a new Zombie and announce it.
	Zombie *walkingdead = newZombie("Walking Dead");

	randomChump("Caminante");
	//Delete the Zombie created with newZombie.
	delete walkingdead;
	return 0;
}
