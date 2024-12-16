/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:20:50 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/18 10:56:10 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : virtual public Animal
{
    public:
        Cat();
        Cat(Cat const &src);
        Cat &operator=(Cat const &src);
        virtual ~Cat();
        void makeSound() const;
};