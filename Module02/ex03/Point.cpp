/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 13:51:00 by saroca-f          #+#    #+#             */
/*   Updated: 2024/09/28 17:56:42 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

Point::Point(): _x(0), _y(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Point::Point(Fixed const x, Fixed const y): _x(x), _y(y)
{
    //std::cout << "Parametric constructor called" << std::endl;
}

Point::Point(const Point &copy): _x(copy._x), _y(copy._y)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Point::~Point()
{
    //std::cout << "Destructor called" << std::endl;
}

const Fixed &Point::getX(void)const
{
    return this->_x;
}

const Fixed &Point::getY(void)const
{
    return this->_y;
}

Point &Point::operator=(const Point& copy)
{
    //std::cout << "Assignation operator called" << std::endl;
    if (this != &copy)
        return (*this);
    return (*this);
}

std::ostream	&operator<<(std::ostream &output, Point const &point)
{
	//outream: standard output stream
	//In this funtion we take the fixed point value and convert it to a float
	//to print it out
	output << "_x: " << point.getX() << " / _y: " << point.getY() << std::endl;
	return (output);
}