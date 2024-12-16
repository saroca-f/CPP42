/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:35:55 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/27 15:58:43 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define N_ANIMALS 10

int main()
{
	//Animal	fail;
	Animal		*perro = new Dog();
	Animal		*gato = new Cat();
	perro->makeSound();
	gato->makeSound();
	delete perro;
	delete gato;
    return 0;
}