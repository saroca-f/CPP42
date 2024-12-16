/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:02:49 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 11:15:42 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.hpp"

class	HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon;

	public:
		HumanA(std::string nameA, Weapon &weaponA);
		~HumanA(void);
		void	attack( void );
		void	setWeapon( Weapon weapon );
};