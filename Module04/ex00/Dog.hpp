/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:22:16 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/18 10:56:17 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : virtual public Animal
{
    public:
        Dog();
        Dog(Dog const &src);
        Dog &operator=(Dog const &src);
        virtual ~Dog();
        void makeSound() const;
};