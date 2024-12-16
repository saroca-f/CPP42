/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:48:08 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/29 12:09:33 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
	std::cout << "IMateriaSource object created" << std::endl;
}

IMateriaSource::IMateriaSource(IMateriaSource const &copy)
{
	*this = copy;
	std::cout << "IMateriaSource object copied" << std::endl;
}

IMateriaSource const &IMateriaSource::operator=(IMateriaSource const &copy)
{
	(void)copy;
	std::cout << "IMateriaSource Assignment Operator Called" << std::endl;
	return *this;
}