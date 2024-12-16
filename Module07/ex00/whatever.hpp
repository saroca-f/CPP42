/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 12:20:08 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/25 12:00:23 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RESET "\033[0m"

template <typename T> void swap(T &first, T &second)
{
	T third;
	third = first;
	first = second;
	second = third;
}

template <typename T> T min(T &first, T &second)
{
	if (first < second)
		return (first);
	return (second);
}

template <typename T> T max(T &first, T &second)
{
	if (first > second)
		return (first);
	return (second);
}