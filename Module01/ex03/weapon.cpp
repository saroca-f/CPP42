/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:20:56 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 10:09:20 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.hpp"

Weapon::Weapon( std::string weapon ): _type(weapon)
{
    return ;
}

Weapon::~Weapon(void)
{
    return ;
}

void    Weapon::setType( std::string newType )
{
    this->_type = newType;
}

const std::string&	Weapon::getType( void )
{
    return (this->_type);
}