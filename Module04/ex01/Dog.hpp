/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:22:16 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/27 14:46:52 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Dog : virtual public Animal
{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(Dog const &src);
        Dog &operator=(Dog const &src);
        virtual ~Dog();
        void buildDogIdeas (std::string const &idea, int const i);
        void getDogIdeas (int const index);
        void makeSound() const;
        Brain *getBrain(void) const
        {
            return (this->_brain);
        };
};