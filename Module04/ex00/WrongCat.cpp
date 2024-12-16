/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:05:27 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/18 11:27:16 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->_type = "WrongCat";
    std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy) : WrongAnimal(copy)
{
    this->_type = copy._type;
    std::cout << "Copy WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "Default WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return (*this);
}

void WrongCat::makeSound(void)const
{
    std::cout << "Woof Woof" << std::endl;
}