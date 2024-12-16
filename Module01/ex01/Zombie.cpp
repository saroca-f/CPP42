/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:46:14 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 08:54:06 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << ": has been created." << std::endl;
}

Zombie::Zombie(void)
{
	static int count = 1;

	this->_name = "(null)";
	std::cout << count++ << "º zombie has been created." << std::endl;
}

Zombie::~Zombie()
{
	static int count = 1;

	std::cout << count++ << "º Zombie " << this->_name << " ha been destroyed" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}
