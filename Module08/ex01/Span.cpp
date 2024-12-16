/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:04:44 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/29 20:02:46 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) {}

Span::Span(unsigned int N)
{
	this->_size = N;
    this->_array[N];
}

Span::Span(const Span &src) {*this = src;}

Span::~Span() {}

void Span::addNumber(int number)
{
	try
	{
		if (this->_array.size() > static_cast<size_t>(this->_size))
			throw (Span::VectorIsFull());
		this->_array.push_back(number);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void Span::addNumber(std::vector<int>::const_iterator begin, std::vector <int> ::const_iterator end)
{
	try
	{
		if (this->_array.size() + std::distance(begin, end) > static_cast<size_t>(this->_size))
			throw (Span::VectorIsFull());
		_array.insert(_array.end() ,begin, end);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}

size_t Span::shortestSpan()
{
	if (!this->_array.size())
		throw Span::VectorIsEmpty();
	if (this->_array.size() < 2)
		throw Span::NotEnoughElements();
	std::vector<int> copy (this->_array); // copy
	std::sort(copy.begin(), copy.end()); //sort elements
	size_t shortest = std::numeric_limits<int>::max();
	for (std::vector<int>::size_type i = 1; i < copy.size(); i++)
	{
		size_t diff = copy[i] - copy[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

size_t Span::longestSpan()
{
	if (!this->_array.size())
		throw Span::VectorIsEmpty();
	if (this->_array.size() < 2)
		throw Span::NotEnoughElements();
	std::vector<int> copy (this->_array); // copy
	size_t diff = *std::max_element(copy.begin(), copy.end()) - *std::min_element(copy.begin(), copy.end());
	return (diff);
}

Span const &Span::operator=(Span const &copy)
{
	_size = copy._size;
	_array = copy._array;
	return (*this);
}

std::ostream &operator<<(std::ostream &output, const Span &src) 
{
	std::vector <int> sortedArray = *src.getArray();
    std::sort(sortedArray.begin(), sortedArray.end());
    for (std::vector<int>::const_iterator it = sortedArray.begin(); it != sortedArray.end(); ++it) 
		output << *it << " ";
    return (output);
}

const char *Span::VectorIsFull::what() const throw()
{
	return(RED "Array is full!" RESET);
}

const char *Span::VectorIsEmpty::what() const throw()
{
	return(RED "Array is empty!" RESET);
}

const char *Span::NotEnoughElements::what() const throw()
{
	return(RED "The array not have enougt elements!" RESET);
}