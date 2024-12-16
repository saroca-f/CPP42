/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:47:36 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/14 13:04:14 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Unnamed_clap_name"), _name("unnamed")
{
    std::cout << "DiamondTrap " << this->_name <<" has been assembled by default" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), _name(name)
{
    this->_hitPoints = FragTrap::getHP();
    this->_energyPoints = ScavTrap::getEP();
    this->_attackDamage = FragTrap::getAD();
    std::cout << "DiamondTrap " << this->_name <<" has been assembled" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &copy)
{
    ClapTrap::operator=(copy);
    ScavTrap::operator=(copy);
    FragTrap::operator=(copy);
    this->_name = copy._name;
    this->_hitPoints = copy._hitPoints;
    this->_energyPoints = copy._energyPoints;
    this->_attackDamage = copy._attackDamage;
    this->_gateKeeperMode = copy._gateKeeperMode;
    std::cout << "DiamondTrap " << this->_name <<" has been assambled by copy" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->_name <<" has been disassembled" << std::endl;
}

void DiamondTrap::whoAmI(void)
{
    if (this->_hitPoints == 0)
    {
        std::cout << this->_name << " is destroyed!!" << std::endl;
        return ;
    }
    else if (this->_energyPoints == 0)
    {
        std::cout << this->_name << " has 0 energy points!" << std::endl;
        return ;
    }
    else
        std::cout << "I am " << this->_name << " and my ClapTrap name is " << this->ClapTrap::_name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    if (this->_hitPoints == 0)
    {
        std::cout << this->_name << " is destroyed!!" << std::endl;
        return ;
    }
    else if (this->_energyPoints == 0)
    {
        std::cout << this->_name << " has 0 energy points!" << std::endl;
        return ;
    }
    else
    {
        ScavTrap::attack(target);
    }
}
