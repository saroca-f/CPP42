/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:07:57 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/29 15:48:29 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "Character.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure object created" << std::endl;
}

Cure::Cure(Cure const &copy) : AMateria(copy)
{
	std::cout << "Cure object copied" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure object destroyed" << std::endl;
}

Cure const &Cure::operator=(Cure const &copy)
{
	AMateria::operator=(copy);
	std::cout << "Cure Assignment Operator Called" << std::endl;
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}