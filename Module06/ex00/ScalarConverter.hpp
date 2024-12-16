/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:40:35 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/21 15:41:36 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <algorithm>

#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
    public:
        static void convert(const std::string &input);
};