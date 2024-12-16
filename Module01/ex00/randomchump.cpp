/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomchump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:47:56 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 08:50:06 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// Function to create a new Zombie that announces itself
// when the program ends, it is destroyed.

void    randomChump(std::string name)
{
    Zombie walking_dead(name);
    walking_dead.announce();
}
