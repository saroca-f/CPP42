/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:42:34 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/27 15:46:18 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include "Brain.hpp"

class Animal
{
    protected:
        std::string _type;
    public:
        Animal();
        Animal(Animal const &copy);
        Animal &operator=(Animal const &copy);
        virtual ~Animal();
        std::string getType() const;
        virtual void makeSound() const = 0;
        virtual Brain *getBrain() const = 0;
};

#endif
