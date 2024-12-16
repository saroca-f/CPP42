/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:09:06 by saroca-f          #+#    #+#             */
/*   Updated: 2024/09/28 18:57:08 by saroca-f         ###   ########.fr       */
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
		//compare
			bool operator<(Fixed fixed)const;
			bool operator>(Fixed fixed)const;
			bool operator>=(Fixed fixed)const;
			bool operator<=(Fixed fixed)const;
			bool operator==(Fixed fixed)const;
			bool operator!=(Fixed fixed)const;
		//math
			Fixed operator+(Fixed fixed)const;
			Fixed operator-(Fixed fixed)const;
			Fixed operator*(Fixed fixed)const;
			Fixed operator/(Fixed fixed)const;
		//increment/decrement
			Fixed operator++(void);
			Fixed operator++(int);
			Fixed operator--(void);
			Fixed operator--(int);
	//public functions
		//convert
		float toFloat(void)const;
		int toInt(void)const;
		//max-min
		static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(Fixed const &first, Fixed const &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(Fixed const &first, const Fixed &second);
	//getters and setters
		int getRawBits(void)const;
		void setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);
