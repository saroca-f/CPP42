/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:46:45 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 08:54:26 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *ZombieHorde( int N, std::string name )
{
    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; i++)
    {  
        horde[i].setName(name);
    }
    return (horde);
}