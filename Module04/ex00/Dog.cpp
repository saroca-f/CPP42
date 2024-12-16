/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:48:34 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/18 10:48:56 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->_type = "Dog";
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
    this->_type = copy._type;
    std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Default Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return (*this);
}

void Dog::makeSound(void)const
{
    std::cout << "Woof Woof" << std::endl;
}