/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:19:53 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/24 14:37:39 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	std::cout << GREEN << "Char Test" << RESET << std::endl << std::endl;
	char cx = 'b';
	char cy = 'a';

	std::cout << "Prev X value: " << RED << cx << RESET << std::endl << "Prev Y value: " << RED << cy << RESET << std::endl;
	swap(cx, cy);
	std::cout << YELLOW << "<swap>" << RESET << std::endl;
	std::cout << "Prev X value: " << RED << cx << RESET << std::endl << "Prev Y value: " << RED << cy << RESET << std::endl;
	std::cout << "The min is: " << RED << min(cx, cy) << RESET << std::endl;
	std::cout << "The max is: " << RED << max(cx, cy) << RESET << std::endl << std::endl;
	
	std::cout << GREEN << "Int Test" << RESET << std::endl << std::endl;
	int ix = 5;
	int iy = 10;

	std::cout << "Prev X value: " << RED << ix << RESET << std::endl << "Prev Y value: " << RED << iy << RESET << std::endl;
	swap(ix, iy);
	std::cout << YELLOW << "<swap>" RESET << std::endl;
	std::cout << "Prev X value: " << RED << ix << RESET << std::endl << "Prev Y value: " << RED << iy << RESET << std::endl;
	std::cout << "The min is: " << RED << min(ix, iy) << RESET << std::endl;
	std::cout << "The max is: " << RED << max(ix, iy) << RESET << std::endl << std::endl;

	std::cout << GREEN << "Double Test" << RESET << std::endl << std::endl;
	double dx = 4.2;
	double dy = 42.0;

	std::cout << "Prev X value: " << RED << dx << RESET << std::endl << "Prev Y value: " << RED << dy << RESET << std::endl;
	swap(dx, dy);
	std::cout << YELLOW << "<swap>" << RESET << std::endl;
	std::cout << "Prev X value: " << RED << dx << RESET << std::endl << "Prev Y value: " << RED << dy << RESET << std::endl;
	std::cout << "The min is: " << RED << min(dx, dy) << RESET << std::endl;
	std::cout << "The max is: " << RED << max(dx, dy) << RESET << std::endl << std::endl;

	return 0;
}