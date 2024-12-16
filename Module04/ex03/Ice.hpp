/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:22:50 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/28 15:50:10 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{	
	public:
		Ice();
		Ice(Ice const &copy);
		~Ice(void);
		Ice const &operator=(Ice const &copy);
		AMateria *clone() const;
		void use(ICharacter &target);
};
