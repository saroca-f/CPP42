/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:21:07 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 10:08:40 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanA.hpp"

// We send weapon like a reference to avoid a copy of the object
// : _name(name), _weapon(weapon) -> This is an initialization list
// HumanA takes is weapon in the constructor

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	std::cout << "HumanA " << name << " created with " << weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA " << this->_name << " destroyed" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
}
