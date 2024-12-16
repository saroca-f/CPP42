/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:20:50 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/27 14:46:19 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class Cat : virtual public Animal
{
    private:
        Brain *_brain;

    public:
        Cat();
        Cat(Cat const &src);
        Cat &operator=(Cat const &src);
        virtual ~Cat();
        void buildCatIdeas (std::string const &idea, int const i);
        void getCatIdeas (int const index);
        void makeSound() const;
        Brain *getBrain(void) const
        {
            return (this->_brain);
        };
};