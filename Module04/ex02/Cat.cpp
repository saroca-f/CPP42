/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:45:08 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/27 13:22:35 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->_brain = new Brain();
    this->_type = "Cat";
    for (int i = 0; i < 100; i++)
        buildCatIdeas("Fish and milk", i);
    std::cout << "Default Cat constructor called" << std::endl;
}

Cat::Cat(Cat const &copy) : Animal(copy)
{
    this->_brain = new Brain();
    this->_type = copy._type;
    std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Default Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &copy)
{
    if (this != &copy)
    {
        Animal::operator=(copy);
        delete(this->_brain);
        this->_brain = new Brain(*copy._brain);
        this->_type = copy._type;
    }
    return (*this);
}

void Cat::buildCatIdeas(std::string const &idea, int const i)
{
    this->_brain->setIdea(idea, i);
}

void Cat::getCatIdeas(int const index)
{
    std::cout << this->_brain->getIdea(index) << std::endl;
}

void Cat::makeSound(void)const
{
    std::cout << "Meow Meow" << std::endl;
}