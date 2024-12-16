/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:25:52 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/15 10:15:44 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

static void valArgs(int argc, char **argv, std::vector<int> &vector, std::deque<int> &deque)
{
	for (size_t i = 1; i < (unsigned int)argc; i++)
	{
		size_t j = 0;
		if (!std::strcmp(argv[i], ""))
			throw std::invalid_argument(BOLD_RED "ERROR: " YELLOW "this program need a positive number integer sequence" RESET);
		if (argv[i][0] == '+')
			j++;
		if (argv[i][0] == '-')
			throw std::invalid_argument(BOLD_RED "ERROR: " YELLOW "this program need a positive number integer sequence" RESET);
		if (!std::strcmp(argv[i], "0"))
			throw std::invalid_argument(BOLD_RED "ERROR: " YELLOW "0 cannot be present as a number" RESET);
		while(argv[i][j])
		{
			if (!std::isdigit(argv[i][j]))
				throw std::invalid_argument(BOLD_RED "ERROR: " YELLOW "this program need a positive number integer sequence" RESET);
			j++;
		}
		long number = atol(argv[i]);
		if (number > INT_MAX)
			throw std::invalid_argument(BOLD_RED "ERROR: " YELLOW "this program need a positive number integer sequence" RESET);
		vector.push_back(static_cast<int>(number));
		deque.push_back(static_cast<int>(number));
	}
}

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		std::cout << BOLD_RED "ERROR: " RESET "incorret number of arguments" << std::endl;
		return (1);
	}
	std::vector<int> vector;
	std::deque<int> deque;
	double tvector, tdeque;
	try
	{
		valArgs(argc, argv, vector, deque);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	std::cout << CYAN "Before: " RESET;
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << "\n";
	tvector = PmergeMe::containerSort(vector);
	tdeque = PmergeMe::containerSort(deque);
	std::cout << CYAN "After: " RESET;
	for (size_t i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << "\n";
	std::cout << "Time to process a range of " MAGENTA << vector.size() << RESET " elements with std::vector : " YELLOW << std::fixed << std::setprecision(6) << tvector / 1000000.0 << GREEN " us\n" RESET;
	std::cout << "Time to process a range of " MAGENTA << deque.size() << RESET " elements with std::deque : " YELLOW << std::fixed << std::setprecision(6) << tdeque / 1000000.0 << GREEN " us\n" RESET;
	return 0;
}
