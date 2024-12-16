/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:26:22 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/15 10:16:01 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <string_view>
#include <sys/time.h>
#include <iterator>
#include <iomanip>
#include <vector>
#include <deque>

#define BLACK		"\033[0;30m"
#define RED			"\033[0;31m"
#define BOLD_RED	"\033[1;31m"
#define GREEN		"\033[0;32m"
#define YELLOW		"\033[0;33m"
#define BOLD_YELLOW	"\033[1;33m"
#define BLUE		"\033[0;34m"
#define MAGENTA		"\033[0;35m"
#define CYAN		"\033[0;36m"
#define WHITE		"\033[0;37m"
#define RESET		"\033[0m"


class PmergeMe
{
	private:
		PmergeMe(void) {}
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &assign);
		~PmergeMe(void) {}
	public:
		template<typename T> static void binarySearch(typename T::iterator &it, typename T::iterator begin, typename T::iterator end, const typename T::value_type &value);
		template<typename T> static void insertLow(T &containerRight, int insert);
		template<typename T> static void mergeInsertSort(T &container);
		template<typename T> static double containerSort(T &container);
};

#endif