/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:14:33 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/14 11:22:43 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap &copy);
        ~FragTrap();
        FragTrap &operator=(const FragTrap &copy);
        void highFivesGuys(void);
        virtual unsigned int getHP(void) const;
        virtual unsigned int getAD(void) const;
};

#endif
