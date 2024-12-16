/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:35:55 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/29 16:37:39 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define N_ANIMALS 10

int main()
{
	{
		const Animal *lotsOfAnimals[N_ANIMALS];

		for (int i = 0; i < N_ANIMALS; i++)
		{
			if (i < N_ANIMALS / 2)
				lotsOfAnimals[i] = new Dog();
			else
				lotsOfAnimals[i] = new Cat();
		}
		std::cout << "-------------------------------------\n";
		Brain *DogBrain = lotsOfAnimals[0]->getBrain();
		Brain *CatBrain = lotsOfAnimals[5]->getBrain();
 		std::cout << lotsOfAnimals[0]->getType() << std::endl;
		std::cout << lotsOfAnimals[5]->getType() << std::endl << std::endl;
		std::cout << "Dog's first thought is \"" << DogBrain->getIdea(0) << "\"" << std::endl;
		std::cout << "Cat's first thought is \"" << CatBrain->getIdea(0) << "\"" << std::endl << std::endl;
		DogBrain->setIdea("I have to chase the postman", 0);
		CatBrain->setIdea("I have to conquer the world", 0);
		std::cout << "Dog's first thought now is \"" <<  DogBrain->getIdea(0) << "\"" << std::endl;
		std::cout << "Cat's first thought now is \"" << CatBrain->getIdea(0) << "\"" << std::endl << std::endl;
		std::cout << "-------------------------------------\n";
		for (int i = 0; i < N_ANIMALS; i++)
			delete lotsOfAnimals[i];
	}
    std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using copy constructor:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog(*dogA);

		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		*dogA = *dogB;
		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using copy constructor:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat(*catA);

		delete catA;
		delete catB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using assignment operator overload:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat;

		*catA = *catB;
		delete catA;
		delete catB;
	}

    return 0;
}