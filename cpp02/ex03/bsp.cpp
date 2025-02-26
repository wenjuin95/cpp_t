/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:14:48 by welow             #+#    #+#             */
/*   Updated: 2025/02/24 14:00:38 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/

/**
 * @brief calculate the area of a triangle
 * @param a Point a
 * @param b Point b
 * @param c Point c
 * @return area of the triangle
 * @note 1. using shoelace formula
 * @note 2. area = (x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2)) / 2
 * @note 3. abs() is used to get the absolute value of the area to avoid negative value
*/
static float get_area(Point const a, Point const b, Point const c)
{
	float area;
	area = ((a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat()))
		+ (b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat()))
		+ (c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()))) / 2;
	return (std::abs(area));
}

/**
 * @brief check if a point is inside a triangle
 * @param a Point a
 * @param b Point b
 * @param c Point c
 * @param p Point p
 * @return true if the point is inside the triangle, false otherwise
 * @note 1. check if found one triangle area is 0 then the point is outside the triangle
 * @note 2. check if the sum of the three triangle areas is equal to the total area of
 * 			the triangle mean the point is in the triangle
*/
bool bsp( Point const a, Point const b, Point const c, Point const p )
{
	float total_area, pab, pbc, pac;

	total_area = get_area(a, b, c);
	pab = get_area(p, a, b);
	pbc = get_area(p, b, c);
	pac = get_area(p, a, c);
	std::cout << "+++++++++++++++++++++++++++++++++" << std::endl; //visualize
	std::cout << "Total area: " << total_area << std::endl << std::endl; //visualize
	std::cout << "Area of PAB: " << pab << std::endl; //visualize
	std::cout << "Area of PBC: " << pbc << std::endl; //visualize
	std::cout << "Area of PAC: " << pac << std::endl; //visualize
	std::cout << "========================" << std::endl; //visualize
	std::cout << "             " << pab + pbc + pac << std::endl; //visualize
	std::cout << "+++++++++++++++++++++++++++++++++" << std::endl; //visualize
	if (pab != 0 && pbc != 0 && pac != 0 && total_area == pab + pbc + pac)
		return (true);
	else
		return (false);
}
