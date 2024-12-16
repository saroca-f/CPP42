/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:31:27 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/05 10:58:32 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED "Incorrect number of arguments!" << std::endl;
		return (1);
	}
	bitcoinExchange(argv[1]);
	return (0);
}