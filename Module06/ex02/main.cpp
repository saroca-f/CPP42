/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:28:10 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/22 18:14:31 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <unistd.h>

Base    *generate(void)
{
	srand((unsigned)time(NULL));
	switch (int success = rand() % 3)
	{
		case 0: 
			return (new A());
		case 1: 
			return (new B());
		case 2: 
			return (new C());
		default: return (NULL);
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << DEFAULT <<"The object is of type " << YELLOW << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << DEFAULT <<"The object is of type " << YELLOW << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << DEFAULT <<"The object is of type " << YELLOW << "C" << std::endl;
	else
		std::cout << RED << "Unknown type" << std::endl;
}

void identify(Base &p)
{
	try
	{
		(void) dynamic_cast<A&>(p);
		std::cout << DEFAULT <<"The object is of type " << BLUE << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		try
		{
			(void) dynamic_cast<B&>(p);
			std::cout << DEFAULT <<"The object is of type " << BLUE << "B" << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				(void) dynamic_cast<C&>(p);
				std::cout << DEFAULT <<"The object is of type " << BLUE << "C" << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << CYAN << "Unknown type" << std::endl;
			}
			
		}	
	}
}

int main(void)
{
	Base *p;
	for (int i = 0; i < 5; i++) {
		std::cout << BROWN << i + 1 << ":" << std::endl;
		p = generate(); identify(p); identify(*p);
		delete p; std::cout << std::endl;
		sleep(1);
	}
	Base *c = NULL;
	identify(c); identify(*c);
	return 0;
}