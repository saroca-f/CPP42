/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:24:50 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/28 15:57:10 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria	*_inventory[4];
	public:
		Character ();
		Character (std::string const &name);
		Character (Character const &copy);
		~Character();
		Character const &operator=(Character const &copy);
		std::string const &getName() const;
		bool lookForMateria(AMateria *m);
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};