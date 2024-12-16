/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 17:52:31 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/29 15:48:49 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Character.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice object created" << std::endl;
}

Ice::Ice(Ice const &copy) : AMateria(copy)
{
	std::cout << "Ice object copied" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice object destroyed" << std::endl;
}

Ice const &Ice::operator=(Ice const &copy)
{
	AMateria::operator=(copy);
	std::cout << "Ice Assignment Operator Called" << std::endl;
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}