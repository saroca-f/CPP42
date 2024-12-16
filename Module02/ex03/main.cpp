/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:09:01 by saroca-f          #+#    #+#             */
/*   Updated: 2024/09/28 18:10:33 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

//if a number with a fractional part not have a coma in the end, is a double
//if a number with a fractional part have a coma in the end, is a float

int main(void)
{
	const Point a(0, 0);
	const Point b(10, 0);
	const Point c(0, 10);
	const Point point(5, 5);

	std::cout << "The point( x= " << point.getX() << "\t\ty= " << point.getY() << "\t) is inside the triangle\n" <<
	"\ta( x= " << a.getX() << "\t\ty= " << a.getY() << "\t)\n" <<
	"\tb( x= " << b.getX() << "\ty= " << b.getY() << "\t)\n" <<
	"\tc( x= " << c.getX() << "\t\ty= " << c.getY() << "\t)\n" << std::endl;
	if (bsp(a, b, c, point) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
	std::cout << "////////////////////////////////////////////////////////////////////" << std::endl;
	Point d(10, 0);
	Point e(0, 10);
	Point f(0, 0);
	Point point2(15, 15);
	std::cout << "The point( x= " << point2.getX() << "\t\ty= " << point2.getY() << "\t) is outside the triangle\n" <<
	"\ta( x= " << d.getX() << "\t\ty= " << d.getY() << "\t)\n" <<
	"\tb( x= " << e.getX() << "\ty= " << e.getY() << "\t)\n" <<
	"\tc( x= " << f.getX() << "\t\ty= " << f.getY() << "\t)\n" << std::endl;
	if (bsp(d, e, f, point2) == true)
		std::cout << "\033[32mTRUE\033[0m" << std::endl;
	else
		std::cout << "\033[31mFALSE\033[0m" << std::endl;
}
