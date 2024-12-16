/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:45:08 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/18 10:48:04 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->_type = "Cat";
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
    this->_type = copy._type;
    std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Default Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return (*this);
}

void Cat::makeSound(void)const
{
    std::cout << "Meow Meow" << std::endl;
}