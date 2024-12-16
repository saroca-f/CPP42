/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:02:53 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/29 16:01:24 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class WrongAnimal
{
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const &copy);
        WrongAnimal &operator=(WrongAnimal const &copy);
        virtual ~WrongAnimal();
        std::string getType() const;
        void makeSound() const;
};