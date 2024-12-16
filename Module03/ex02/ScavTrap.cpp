/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:29:16 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/14 12:53:31 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap(), _gateKeeperMode(false)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name <<" has been assembled by default" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name) , _gateKeeperMode(false)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name <<" has been assembled" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
    *this = copy;
    std::cout << "ScavTrap " << this->_name <<" has been assembled by copy" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scavtrap " << this->_name <<" has been disassembled" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &copy)
{
    ClapTrap::operator=(copy);
	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
    this->_gateKeeperMode = copy._gateKeeperMode;
	return (*this);
}

void ScavTrap::guardGate()
{
    if (this->_hitPoints == 0)
    {
        std::cout << this->_name << " is destroyed!!" << std::endl;
        return ;
    }
    if (this->_gateKeeperMode == false && this->_energyPoints == 0)
    {
        std::cout << this->_name << " has 0 energy points!" << std::endl;
        return ;
    }
    if (this->_gateKeeperMode == false)
    {
        std::cout << this->_name << " has entered in Gate Keeper Mode" << std::endl;
        this->_gateKeeperMode = true;
    }
    else
    {
        std::cout << this->_name << " has exited from Gate Keeper Mode" << std::endl;
        this->_gateKeeperMode = false;
    }
}

void ScavTrap::getEnergyPoints()
{
    std::cout << "Energy points: " << this->_energyPoints << std::endl;
}
