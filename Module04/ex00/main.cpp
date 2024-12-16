/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:35:55 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/29 16:03:32 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal		*meta = new Animal();
	const Animal		*j = new Dog();
	const Animal		*i = new Cat();
	const WrongAnimal	*k = new WrongCat();
    const WrongCat      *c = new WrongCat();

	i->makeSound();
	j->makeSound();
	k->makeSound();
	meta->makeSound();
    c->makeSound();
	delete meta;
	delete i;
	delete j;
	delete k;
    delete c;
}