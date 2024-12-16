/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:48:51 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/29 13:25:13 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() , _learnInventory()
{
    std::cout << "MateriaSource object created" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i])
			delete this->_learnInventory[i];
	}
	std::cout << "MateriaSource destroyed" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const &copy) : IMateriaSource(copy), _learnInventory()
{
	*this = copy;
	std::cout << "MateriaSource object copied" << std::endl;
}

MateriaSource const &MateriaSource::operator=(MateriaSource const &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy._learnInventory[i])
			this->_learnInventory[i] = copy._learnInventory[i]->clone();
	}
	std::cout << "MateriaSource Assignment Operator Called" << std::endl;
	return *this;
}

bool	MateriaSource::lookForLearnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if(this->_learnInventory[i] == m)
			return true;
	}
	return false;
}

void MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
	{
		std::cout << "Cannot learn invalid materia" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_learnInventory[i])
		{
			if (this->lookForLearnMateria(m))
				this->_learnInventory[i] = m->clone();
			else
				this->_learnInventory[i] = m;
			std::cout << m->getType() << " is learned in slot " << i + 1 << std::endl;
			return ;
		}
	}
	std::cout << "Learn memory is full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_learnInventory[i] && this->_learnInventory[i]->getType() == type)
			return (this->_learnInventory[i]->clone());
	}
	std::cout << "Cannot create materia, " << type << " is invalid!" << std::endl;
	return (0);	
}
