/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:09:11 by saroca-f          #+#    #+#             */
/*   Updated: 2024/09/26 12:56:13 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


//Static variable that was declared outside the class
const int Fixed::_fract_bits = 8;

//Constructors

Fixed::Fixed(): _fp_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    // In the copy constructor, we want to copy the value of the object passed as an argument
    // We call the assignment operator to do this
    *this = copy;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    // We need to convert the int value to a fixed point value
    // We do this by shifting the value to the left by the number of fractional bits
    // This is the same as multiplying by 2^_fract_bits
    this->_fp_value = value << this->_fract_bits;
}

Fixed::Fixed(const float input)
{
	std::cout << "Float Constructor called" << std::endl;
    // We need to convert the float value to a fixed point value
    // We do this by multiplying the float value by 2^_fract_bits  
    // In this case es 2^8 = 256, and after multiplicated by input
    // ex: 2.5 * 256 = 640
	this->_fp_value = roundf(input * (1 << this->_fract_bits));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}


float	Fixed::toFloat(void)const
{
    //In this case divides the fixed point value by 2^_fract_bits
    //ex: 640 / 256 = 2.5
	return ((float)this->_fp_value / (float)(1 << this->_fract_bits));
}

int	Fixed::toInt(void)const
{
	return (this->_fp_value >> this->_fract_bits);
}

int Fixed::getRawBits(void)const
{
    return this->_fp_value;
}

void	Fixed::setRawBits(int const raw)
{
	this->_fp_value = raw;
}

Fixed	&Fixed::operator=(const Fixed &src)
{
    //If a = b, b is the src and a is the 'this' pointer
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fp_value = src.getRawBits();
	return *this;
}

//outream: standard output stream
//In this funtion we take the fixed point value and convert it to a float
//to print it out
std::ostream	&operator<<(std::ostream &output, Fixed const &fixed)
{
	output << fixed.toFloat();
	return (output);
}
