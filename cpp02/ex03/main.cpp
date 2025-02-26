/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:05:38 by welow             #+#    #+#             */
/*   Updated: 2025/02/24 14:13:05 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const p );

void	printIsPointInsideTriangle(Point const a, Point const b, Point const c, Point const p)
{
	std::cout << CYAN "Triangle: A(" << a.getX() << ", " << a.getY() << ") "
		<< "| B(" << b.getX() << ", " << b.getY() << ") "
		<< "| C(" << c.getX() << ", " << c.getY() << ")" << std::endl
		<< "Point   : P(" << p.getX() << ", " << p.getY() << ")" RESET << std::endl;
	if (bsp(a, b, c, p) == true)
		std::cout << GREEN "inside" RESET<< std::endl;
	else
		std::cout << RED "not inside" RESET << std::endl;
}

int	main( void )
{
	{
		Point	a(0, 0);
		Point	b(10, 30);
		Point	c(20, 0);
		Point	p(10, 15);
		printIsPointInsideTriangle(a, b, c, p);
	}
	std::cout << std::endl << "===============================================" << std::endl << std::endl;
	{
		Point	a(0, 0);
		Point	b(5, 5);
		Point	c(0, 10);
		Point	p(2.5f, 2.5f);
		printIsPointInsideTriangle(a, b, c, p);
	}
	std::cout << std::endl << "===============================================" << std::endl << std::endl;
	{
		Point	a(-5.44f, 0.29f);
		Point	b(2.62f, 2.95f);
		Point	c(1.0f, -1.45f);
		Point	p(-5.43f, 0.29f);
		printIsPointInsideTriangle(a, b, c, p);
	}
	std::cout << std::endl << "===============================================" << std::endl << std::endl;
	{
		Point	a(0, 0);
		Point	b(6, 0);
		Point	c(0, 6);
		Point	p(2.02f, 0.05f);
		printIsPointInsideTriangle(a, b, c, p);
	}
	return 0;
}
