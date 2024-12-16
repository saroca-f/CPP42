/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:03:04 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/29 20:00:51 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	std::cout << "----------------------" << std::endl;
	std::cout << "|||   NUMBER TEST ||||" << std::endl;
	std::cout << "----------------------" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(10);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << "|||   ARRAY  TEST ||||" << std::endl;
	std::cout << "----------------------" << std::endl;
		Span string(5);
		string.addNumber(sp.getArray()->begin(), sp.getArray()->end());
		std::cout << string.shortestSpan() << std::endl;
		std::cout << string.longestSpan() << std::endl;
		std::cout << string << std::endl;
		return 0;
}