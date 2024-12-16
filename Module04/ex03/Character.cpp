/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:46:35 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/29 17:10:36 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : ICharacter(), _name ("someone"), _inventory()
{
	std::cout << "Character object created" << std::endl;
}

Character::Character(const std::string &name) : ICharacter(), _name (name), _inventory()
{
	std::cout << "Character object created" << std::endl;
}

Character::Character (Character const &copy) : ICharacter(copy),  _name(copy._name), _inventory()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
	}
	std::cout << "Character copied" << std::endl;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete _inventory[i];
	}
	std::cout << "Character destroyed" << std::endl;
}

Character const	&Character::operator=(const Character &copy)
{
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (copy._inventory[i])
			this->_inventory[i] = copy._inventory[i]->clone();
	}
	return (*this);
}

std::string const &Character::getName() const
{
	return (this->_name);
}

bool	Character::lookForMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if(this->_inventory[i] == m)
			return true;
	}
	return false;
}

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Invalid materia!" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			if (this->lookForMateria(m))
				this->_inventory[i] = m->clone();
			else
				this->_inventory[i] = m;
			std::cout << m->getType() << " is equiped in slot " << i + 1 << std::endl;
			return ;
		}
	}
	std::cout << "No free slot!" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 4 || idx < 0)
	{
		std::cout << "Incorrect slot number" << std::endl;
		return ;
	}
	if (this->_inventory[idx])
	{
		std::cout << this->_inventory[idx]->getType() << " was remove of " << idx + 1<< " slot" << std::endl;
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << "Slot " << idx << " is empty" << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 4 || idx < 0)
	{
		std::cout << "Incorrect slot number" << std::endl;
		return ;
	}
	if (this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "Slot " << idx + 1 << " is empty" << std::endl;
}
