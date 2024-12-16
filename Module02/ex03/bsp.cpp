/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:23:41 by saroca-f          #+#    #+#             */
/*   Updated: 2024/09/28 19:38:06 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

static Fixed   get_area(Point const a, Point const b, Point const c)
{
    Fixed area = ((a.getX() * (b.getY() - c.getY()) \
                + (b.getX() * (c.getY() - a.getY())) \
                + (c.getX() * (a.getY() - b.getY())))) / 2;
    if (area < 0)
        area = area * -1;
    return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed area = get_area(a, b, c);
    Fixed d1 = get_area(point, a, b);
    Fixed d2 = get_area(point, b, c);
    Fixed d3 = get_area(point, c, a);
    bool result = false;

    if (area == (d1 + d2 + d3))
        result = true;
    if (d1 == 0 || d2 == 0 || d3 == 0)
        result = false;

    return (result);
}