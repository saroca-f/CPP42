/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:09:06 by saroca-f          #+#    #+#             */
/*   Updated: 2024/09/25 15:50:07 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_fp_value;
		static const int _fract_bits;

	public:
		//constructors
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(const Fixed& copy);
		//destructor
		~Fixed();
		//operators
		Fixed &operator=(const Fixed &src);
		//public functions
		float toFloat(void)const;
		int toInt(void)const;
		//getters and setters
		int getRawBits(void)const;
		void setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
