/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:17:28 by saroca-f          #+#    #+#             */
/*   Updated: 2024/09/28 17:41:56 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

class Point
{
    private:
        Fixed const _x;
        Fixed const _y;

    public:
        Point();
        Point(Fixed const _x, Fixed const _y);
        Point(const Point& copy);
        ~Point();

        Point &operator=(const Point& copy);

		const Fixed &getX(void)const;
		const Fixed &getY(void)const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);