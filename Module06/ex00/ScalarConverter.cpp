/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:36:04 by saroca-f          #+#    #+#             */
/*   Updated: 2025/01/25 18:17:22 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static void printChar(const std::string &input)
{
	std::cout << YELLOW << "char: " << RESET << "'" << input[0] <<"'" << std::endl;
	std::cout << YELLOW << "int: " << RESET << static_cast<int>(input[0]) << std::endl;
	std::cout << YELLOW << "float: " << RESET << static_cast<float>(input[0]) << "f" << std::endl;
	std::cout << YELLOW << "double: " << RESET << static_cast<double>(input[0]) <<  std::endl;
}

static bool isDigit(const std::string &input)
{
	int i = 0;
	if (input[i] == '-') {i++;}
	for (; i < (int)input.length(); i++)
	{
		if (!std::isdigit(input[i]))
			return false;
	}
	if (input.find('.') != std::string::npos)
		return (false);
	return (true);
}

static void printInt(const std::string &input)
{
	int i = std::strtol(input.c_str(), NULL, 10);
	long double value;
	std::istringstream iss(input); iss >> value;
	//char
	if (value < 32 || value > 126)
		std::cout << YELLOW << "char: " << RED << "Non displayable" << std::endl;
	else
		std::cout << YELLOW << "char: " << RESET << "'" << static_cast<char>(i) << "'" << std::endl;
	//int
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << YELLOW << "int:" << RED << " impossible" << std::endl;
	else
		std::cout << YELLOW << "int: " << RESET << i << std::endl;
	//float
	if (value > std::numeric_limits<int>::max())
		std::cout << YELLOW << "float:" << RED << " inff" << std::endl;
	else if (value < -std::numeric_limits<int>::max())
		std::cout << YELLOW << "float:" << RED << " -inff" << std::endl;
	else
		std::cout << YELLOW << "float: " << RESET << static_cast<float>(i) << ".0f" << std::endl;
	//double
	if (value > std::numeric_limits<int>::max())
		std::cout << YELLOW << "double:" << RED << " inf" << std::endl;
	else if (value < -std::numeric_limits<int>::max())
		std::cout << YELLOW << "double:" << RED << " -inf" << std::endl;
	else
		std::cout << YELLOW << "double: " << RESET << static_cast<double>(i) << ".0" << std::endl;
}

static bool isFloat(const std::string &input)
{
	int i = 0;
	if (input[i] == '-') {i++;}
	if (std::count(input.begin(), input.end(), '.') != 1)
		return (false);
	for (; i < (int)input.length() - 1; i++)
	{
		if (!std::isdigit(input[i]) && input[i] != '.')
			return false;
	}
	if (input[input.length() - 1] != 'f' && input[input.length() - 1] != 'F')
		return false;
	return (true);
}

static void printFloat(const std::string &input)
{
	float f = std::strtof(input.c_str(), NULL);
	long double value;
	std::istringstream iss(input); iss >> value;
	//char
	if (value < 32 || value > 126)
		std::cout << YELLOW << "char: " << RED << "Non displayable" << std::endl;
	else
		std::cout << YELLOW << "char: " << RESET << "'" << static_cast<char>(f) << "'" << std::endl;
	//int
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << YELLOW << "int:" << RED <<" impossible" << std::endl;
	else
		std::cout << YELLOW << "int: " << RESET << static_cast<int>(f) << std::endl;
	//float
	if (value > std::numeric_limits<float>::max())
		std::cout << YELLOW << "float: " << RED << "inff" << std::endl;
	else if (value < -std::numeric_limits<float>::max())
		std::cout << YELLOW << "float: " << RED << "-inff" << std::endl;
	else
		std::cout << YELLOW << "float: " << RESET << f << "f" << std::endl;
	//double
	if (value > std::numeric_limits<float>::max())
		std::cout << YELLOW << "double:" << RED << " inf" << std::endl;
	else if (value < -std::numeric_limits<float>::max())
		std::cout << YELLOW << "double:" << RED << " -inf" << std::endl;
	else
		std::cout << YELLOW << "double: " << RESET << static_cast<double>(f) << std::endl;
}

static bool isDouble(const std::string &input)
{
	int i = 0;
	if (input[i] == '-' || input[i] == '+') {i++;}
	if (std::count(input.begin(), input.end(), '.') != 1)
		return (false);
	for (; i < (int)input.length(); i++)
	{
		if (!std::isdigit(input[i]) && (input[i] != '.'))
			return false;
	}
	return (true);
}

static void printDouble(const std::string &input)
{
	double d = std::strtod(input.c_str(), NULL);
	long double value;
	std::istringstream iss(input); iss >> value;
	//char
	if (value < 32 || value > 126)
		std::cout << YELLOW << "char: " << RED << "Non displayable" << std::endl;
	else
		std::cout << YELLOW << "char: " << RESET << "'" << static_cast<char>(d) << "'" << std::endl;
	//int
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		std::cout << YELLOW << "int:" << RED <<" impossible" << std::endl;
	else
		std::cout << YELLOW << "int: " << RESET << static_cast<int>(d) << std::endl;
	//float
	if (value > std::numeric_limits<float>::max())
		std::cout << YELLOW << "float:" << RED << " inff" << std::endl;
	else if (value < -std::numeric_limits<float>::max())
		std::cout << YELLOW << "float:" << RED << " -inff" << std::endl;
	else
		std::cout << YELLOW << "float: " << RESET << static_cast<float>(d) << "f" << std::endl;
	//double
	if (value > std::numeric_limits<double>::max())
		std::cout << YELLOW << "double:" << RED << " inf" << std::endl;
	else if (value < -std::numeric_limits<double>::max())
		std::cout << YELLOW << "double:" << RED << " -inf" << std::endl;
	else
		std::cout << YELLOW << "double: " << RESET << d << std::endl;
}

static std::string errorDetect(const std::string &input)
{
	std::string error;
	
	if (input == "inf" || input == "+inf")
		error = "inf";
	else if (input == "-inf")
		error = "-inf";
	else
		error = "nan";
	return error;
}

void ScalarConverter::convert(const std::string &input)
{
	if (input.empty()) 
		throw std::runtime_error("Invalid input");
	if (input.length() == 1 && !std::isdigit(input[0]))
		return (printChar(input));
	else if (isDigit(input))
		return (printInt(input));
	else if (isFloat(input))
		return (printFloat(input));
 	else if (isDouble(input))
		return (printDouble(input));
	else 
	{
		std::string error = errorDetect(input);
		std::cout << YELLOW << "char:" << RED << " impossible" << RESET << std::endl;
		std::cout << YELLOW << "int:" << RED << " impossible" << RESET << std::endl;
		std::cout << YELLOW << "float: " << RED << error << "f" << RESET  << std::endl;
		std::cout << YELLOW << "double: " << RED << error << RESET  << std::endl;
	}
}