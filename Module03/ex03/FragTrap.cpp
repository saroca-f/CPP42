/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:14:10 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/14 13:07:57 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " has been assembled by default" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " has been assembled" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
{
    ClapTrap::operator=(copy);
    *this = copy;
    std::cout << "FragTrap " << this->_name << " has been assembled by copy" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " has been disassembled" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &copy)
{
    ClapTrap::operator=(copy);
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    if (this->_hitPoints == 0)
    {
        std::cout << this->_name << " is destroyed!!" << std::endl;
        return ;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << this->_name << " has 0 energy points!" << std::endl;
        return ;
    }
    std::cout << this->_name << " stands up his hand and say \"High five, dude!\"" << std::endl;
}

unsigned int FragTrap::getHP(void) const
{
    return (100);
}

unsigned int FragTrap::getAD(void) const
{
    return (30);
}
