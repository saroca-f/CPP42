/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:29:31 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/15 12:13:29 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap &copy);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &copy);
        void guardGate();
        void attack(const std::string& target);
        void getEnergyPoints();
    private:
        bool _gateKeeperMode;
};