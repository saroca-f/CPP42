/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:23:11 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/15 10:18:13 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <stdlib.h> 
#include <string>
#include <sstream>
#include <stack>

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

void RPN(std::string str);