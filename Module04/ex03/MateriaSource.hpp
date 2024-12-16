/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:26:11 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/28 18:30:27 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
		AMateria	*_learnInventory[4];
    public:
		MateriaSource();
		MateriaSource(MateriaSource const &copy);
		virtual ~MateriaSource();
		MateriaSource const &operator=(MateriaSource const &copy);
		void learnMateria(AMateria *m);
        bool lookForLearnMateria(AMateria* m);
		AMateria *createMateria(std::string const &type);
};