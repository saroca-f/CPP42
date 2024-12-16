/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:09:11 by saroca-f          #+#    #+#             */
/*   Updated: 2024/09/28 18:57:36 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


//Static variable that was declared outside the class
const int Fixed::_fract_bits = 8;

//Constructors

Fixed::Fixed(): _fp_value(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	// In the copy constructor, we want to copy the value of the object passed as an argument
	// We call the assignment operator to do this
    //std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int value)
{
	// We need to convert the int value to a fixed point value
	// We do this by shifting the value to the left by the number of fractional bits
	// This is the same as multiplying by 2^_fract_bits
    //std::cout << "Int constructor called" << std::endl;
    this->_fp_value = value << this->_fract_bits;
}

Fixed::Fixed(const float input)
{
	// We need to convert the float value to a fixed point value
	// We do this by multiplying the float value by 2^_fract_bits  
	// In this case es 2^8 = 256, and after multiplicated by input
	// ex: 2.5 * 256 = 640
	//std::cout << "Float Constructor called" << std::endl;
	this->_fp_value = roundf(input * (1 << this->_fract_bits));
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

//Operators

bool	Fixed::operator<(Fixed fixed)const
{
	//This function is used to compare two fixed point values
	//If we have a < b, a is the 'this' pointer and b is the src
    return (this->_fp_value < fixed.getRawBits());
}

bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

//maths

Fixed Fixed::operator+(Fixed fixed)const
{
	Fixed result;
	result.setRawBits(this->getRawBits() + fixed.getRawBits());
	return(result);
}

Fixed Fixed::operator-(Fixed fixed)const
{
	Fixed result;
	result.setRawBits(this->getRawBits() - fixed.getRawBits());
	return(result);
}

Fixed Fixed::operator*(Fixed fixed)const
{
	Fixed result;
	result.setRawBits(this->getRawBits() * fixed.getRawBits());
	result.setRawBits(result.getRawBits() >> this->_fract_bits);
	return(result);
}

Fixed Fixed::operator/(Fixed fixed)const
{
	Fixed result;
	result.setRawBits((this->getRawBits() << this->_fract_bits)/ fixed.getRawBits());
	result.setRawBits(result.getRawBits());
	return(result);
}

//increment/decrement

Fixed Fixed::operator++(void) //prefix ++a
{
	this->_fp_value++;
	return (*this);
}

Fixed Fixed::operator++(int) //postfix a++
{
	Fixed tmp(*this); //Create a copy of the object
	operator++();	  //Call the prefix operator
	return tmp;		  //Return the copy
}

Fixed Fixed::operator--(void) //prefix --a
{
	this->_fp_value--;
	return (*this);
}

Fixed Fixed::operator--(int) //postfix a--
{
	Fixed tmp(*this); //Create a copy of the object
	operator--();	  //Call the prefix operator
	return tmp;		  //Return the copy
}

//public functions

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

Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

std::ostream	&operator<<(std::ostream &output, Fixed const &fixed)
{
	//outream: standard output stream
	//In this funtion we take the fixed point value and convert it to a float
	//to print it out
	output << fixed.toFloat();
	return (output);
}