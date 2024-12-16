/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:48:34 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/27 14:49:41 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
    this->_brain = new Brain();
    this->_type = "Dog";
    for (int i = 0; i < 100; i++)
        buildDogIdeas("Bones and meat", i);
    std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &copy) : Animal(copy)
{
    this->_brain = new Brain(*copy._brain);
    this->_type = copy._type;
    std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Default Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &copy)
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

void Dog::buildDogIdeas(std::string const &idea, int const i)
{
    this->_brain->setIdea(idea, i);
}

void Dog::getDogIdeas(int const index)
{
    std::cout << this->_brain->getIdea(index) << std::endl;
}

void Dog::makeSound(void)const
{
    std::cout << "Woof Woof" << std::endl;
}