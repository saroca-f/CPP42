/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:02:48 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/24 19:01:58 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const &src);
        WrongCat &operator=(WrongCat const &src);
        virtual ~WrongCat();
        void makeSound() const;
};