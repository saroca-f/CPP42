/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:26:39 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/15 10:15:55 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &assign)
{
	(void)assign;
	return *this;
}

template<typename T>
void PmergeMe::binarySearch(typename T::iterator &it, typename T::iterator begin, typename T::iterator end, const typename T::value_type &value)
{
	it = std::lower_bound(begin, end, value);
}

template<typename T>
void PmergeMe::insertLow(T &container, int insert)
{
	typename T::iterator it;
	PmergeMe::binarySearch<T>(it, container.begin(), container.end(), insert);
	container.insert(it, insert);
}

template<typename T>
void PmergeMe::mergeInsertSort(T &container)
{
	if (container.size() <= 1)
		return;
	for (typename T::iterator it = container.begin(); it != container.end() && it + 1 != container.end(); it += 2)
	{
		if (*it > *(it + 1))
			std::swap(*it, *(it + 1));
	}
	T bigRun, smallRun;
	typename T::iterator it = container.begin();
	for (size_t i = 0; it != container.end(); ++it, ++i)
	{
		if (i % 2 == 0)
			bigRun.push_back(*it);
		else
			smallRun.push_back(*it);
	}
	mergeInsertSort(bigRun);
	mergeInsertSort(smallRun);
	for (typename T::iterator it = smallRun.begin(); it != smallRun.end(); ++it)
		insertLow(bigRun, *it);
	container = bigRun;
}

template<typename T>
double PmergeMe::containerSort(T &container)
{
	struct timeval start, end;
	gettimeofday(&start, NULL);
	mergeInsertSort(container);
	gettimeofday(&end, NULL);
	long seconds = (end.tv_sec - start.tv_sec) * 1000000.0;
	long microseconds = end.tv_usec - start.tv_usec;

	return seconds + microseconds;
}

template void PmergeMe::binarySearch <std::vector<int> > (std::vector<int>::iterator &it, std::vector<int>::iterator begin, std::vector<int>::iterator end, const std::vector<int>::value_type &value);
template void PmergeMe::binarySearch <std::deque<int> > (std::deque<int>::iterator &it, std::deque<int>::iterator begin, std::deque<int>::iterator end, const std::deque<int>::value_type &value);
template void PmergeMe::insertLow <std::vector<int> >(std::vector<int>&, int insert);
template void PmergeMe::insertLow <std::deque<int> >(std::deque<int>&, int insert);
template void PmergeMe::mergeInsertSort <std::vector<int> >(std::vector<int>&);
template void PmergeMe::mergeInsertSort <std::deque<int> >(std::deque<int>&);
template double PmergeMe::containerSort <std::vector<int> >(std::vector<int>&);
template double PmergeMe::containerSort <std::deque<int> >(std::deque<int>&);
