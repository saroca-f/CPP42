/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:38:57 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/27 13:15:25 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain (void)
{
    std::cout << "Brain created by default." << std::endl;
}

Brain::Brain (Brain const &copy)
{
	*this = copy;
	std::cout << "Brain was be copy." << std::endl;
}

Brain::~Brain ()
{
    std::cout << "Brain was be destroy." << std::endl;
}

Brain const &Brain::operator=(Brain const &copy)
{
	std::copy(copy._ideas, copy._ideas + 100, this->_ideas);
	std::cout << "Assignment operator for Brain called." << std::endl;
	return (*this);
}

std::string const Brain::getIdea(int const &index)const
{
    if (index >= 0 && index < 100)
    {
        return (this->_ideas[index]);        
    }
    return (this->_ideas[0]);
}

void Brain::setIdea(std::string const &idea, int const index)
{
    if (index >= 0 && index < 100)
        this->_ideas[index] = idea;
}