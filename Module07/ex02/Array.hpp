/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:51:23 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/26 15:40:09 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

template <typename T> class Array
{
	private:
		T *_array;
		size_t _size;
	public:
		Array() : _array(NULL), _size(0) {}

		Array(unsigned int size) : _array(NULL) , _size(size)
		{
			if (this->_size == 0)
				throw std::out_of_range("Index out of range");
			this->_array = new T[_size]();
		}

		Array(const Array &copy) : _array(NULL), _size(0)
		{
			*this = copy;
		}

		~Array() 
		{
			if (this->_array != NULL)
				delete[] _array;
		}

		Array &operator=(const Array &copy)
		{
			if (this->_array != NULL)
			{
				delete[] this->_array;
			}
			if (copy._size != 0)
			{
				this->_array = new T[copy._size]();
				for (unsigned int i = 0; i < this->size(); i++)
						this->_array[i] = copy._array[i];
				this->_size = copy._size;
			}
			return (*this); 
		}

		T &operator[](size_t i)
		{
			if (i >= this->_size)
				throw std::out_of_range("Index out of range");
			return(this->_array[i]);
		}
		
		size_t size() 
		{
			return (_size);
		}
};