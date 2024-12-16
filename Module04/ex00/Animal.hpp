/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:42:34 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/18 11:40:56 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

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
        virtual void makeSound() const;
};

#endif
