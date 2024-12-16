/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:21:01 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 10:08:38 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_weapon = NULL;

    this->_name = name;
    std::cout << "HumanB " << this->_name << " created without weapon." << std::endl;
}

HumanB::~HumanB(void)
{
    std::cout << "HumanB " << this->_name << " destroyed." << std::endl;
}

void    HumanB::attack(void)
{
    if (this->_weapon)
        std::cout << "HumanB " << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
    else
        std::cout << "HumanB " << this->_name << " attacks with his bare hands." << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    std::cout << "HumanB " << this->_name << " has equipped a " << this->_weapon->getType() << std::endl;
}
