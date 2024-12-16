/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:42:53 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 09:13:17 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

bool isnumber(std::string str)
{
    if (!str[0])
        return false;
    for (int i = 0; str[i]; i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}

int main()
{
    // Ask the user for the number of zombies in the horde. Check if the input is a number. If not, ask again.
    std::string input;
    while (1)
    {
        std::cout << "Enter the number of zombies in the horde: " << std::endl;
        std::cin >> input;
        while ((isnumber(input) == false))
        {
            std::cout << "Invalid input. Please enter a unsigned and positive number." << std::endl;
            std::cin >> input;
        }
        break;
    }
    std::istringstream iss(input);
	int size;
	if (!(iss >> size))
	{
    	std::cerr << "Invalid input: not a valid integer" << std::endl;
		return 1;
	}
    // Initiate the horde of zombies.
    Zombie  *horde = ZombieHorde(size, "Walking Dead");

    // All zombies in the horde announce themselves.
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << "º ";
        horde[i].announce();
    }
    
    // Delete the Zombie created with newZombie.
    delete[] horde;
    return 0;
}
