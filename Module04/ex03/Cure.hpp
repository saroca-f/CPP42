/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:31:29 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/28 15:50:06 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{	
	public:
		Cure();
		Cure(Cure const &copy);
		~Cure(void);
		Cure const &operator=(Cure const &copy);
		virtual AMateria *clone() const;
		virtual void use(ICharacter &target);
};