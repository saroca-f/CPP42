/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:29:53 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/15 10:20:41 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define F std::cout

#include "RPN.hpp"

static int apply_operator(int a, int b, char op)
{
    switch (op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0)
                throw std::runtime_error(BOLD_RED "ERROR" RESET);
            return a / b;
        default:
            throw std::runtime_error(BOLD_RED "ERROR" RESET);
    }
}

static int numbercheck(std::string str)
{
	int i = 0;
	if(str[0] == '-' && str.size() != 1)
		i++;
	if(str[0] == '-' && str.size() == 1)
		return 0;
	while(i < (int)str.size())
	{
		if (!std::isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

static void resolve(std::stack<int> &elements, const std::string &token)
{
	if (numbercheck(token))
		elements.push(atoi(token.c_str()));
	else
	{
		if (elements.size() < 2)
			throw std::runtime_error(BOLD_RED "ERROR" RESET);
		int b = elements.top();
		elements.pop();
		int a = elements.top();
		elements.pop();
		elements.push(apply_operator(a, b, token[0]));
	}
}

void RPN(std::string str)
{
	std::stack<int> elements;
	std::string token;
	std::istringstream iss(str);
	while (iss >> token)
	{
		if (token.length() != 1 || (!numbercheck(token) && token != "+" && token != "-" && token != "*" && token != "/"))
			throw std::runtime_error(BOLD_RED "ERROR" RESET);
		resolve(elements, token);
	}
	if (elements.size() != 1)
		throw std::runtime_error(BOLD_RED "ERROR" RESET);
	std::cout << GREEN << elements.top() << RESET "\n";
}