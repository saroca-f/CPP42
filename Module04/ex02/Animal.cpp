/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:48:38 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/18 10:44:36 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Default Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &copy)
{
    this->_type = copy._type;
    std::cout << "Copy Animal constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Default Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return (*this);
}

void Animal::makeSound(void)const
{
	std::cout << "This animal doesn't make any sound." << std::endl;
}

std::string	Animal::getType(void)const
{
	return (this->_type);
}