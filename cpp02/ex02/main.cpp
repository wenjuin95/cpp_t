/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:49:29 by welow             #+#    #+#             */
/*   Updated: 2025/02/24 12:26:45 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	{
		std::cout << "----------pdf test----------" << std::endl;
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		if (CALL == 1)
		std::cout << "fixed a: " << std::endl;
		std::cout << a << std::endl;
		std::cout << "pre-increament fixed a: " << std::endl;
		std::cout << ++a << std::endl;
		std::cout << "fixed a: " << std::endl;
		std::cout << a << std::endl;
		std::cout << "before post-increament fixed a: " << std::endl;
		std::cout << a++ << std::endl;
		std::cout << "after post-increament fixed a: " << std::endl;
		std::cout << a << std::endl;
		std::cout << "fixed b: " << std::endl;
		std::cout << b << std::endl;
		std::cout << "find min in fixed a and fixed b " << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	{
		std::cout << std::endl << "----------comparison operator----------" << std::endl;
		Fixed a(20);
		Fixed b(10);

		std::cout << "a: " << a << ", b: " << b << std::endl;
		bool res = a > b;
		if (res == true)
			std::cout << "check a > b:  " << GREEN << "YES" << RESET << std::endl;
		else
			std::cout << "check a > b:  " << RED << "NO" << RESET << std::endl;

		res = a < b;
		if (res == true)
			std::cout << "check a < b:  " << GREEN << "YES" << RESET << std::endl;
		else
			std::cout << "check a < b:  " << RED << "NO" << RESET << std::endl;

		res = a >= b;
		if (res == true)
			std::cout << "check a >= b: " << GREEN << "YES" << RESET << std::endl;
		else
			std::cout << "check a >= b: " << RED << "NO" << RESET << std::endl;

		res = a <= b;
		if (res == true)
			std::cout << "check a <= b: " << GREEN << "YES" << RESET << std::endl;
		else
			std::cout << "check a <= b: " << RED << "NO" << RESET << std::endl;

		res = a == b;
		if (res == true)
			std::cout << "check a == b: " << GREEN << "YES" << RESET << std::endl;
		else
			std::cout << "check a == b: " << RED << "NO" << RESET << std::endl;

		res = a != b;
		if (res == true)
			std::cout << "check a != b: " << GREEN << "YES" << RESET << std::endl;
		else
			std::cout << "check a != b: " << RED << "NO" << RESET << std::endl;

	}

	{
		std::cout << std::endl << "----------arithmetic operator----------" << std::endl;
		Fixed a(20);
		Fixed b(10);
		//Fixed b(0); //it will cause error because it will divide by zero but pdf accept

		std::cout << "a: " << a << ", b: " << b << std::endl;
		Fixed c = a + b;
		std::cout << "a + b = " << c << std::endl;

		c = a - b;
		std::cout << "a - b = " << c << std::endl;

		c = a * b;
		std::cout << "a * b = " << c << std::endl;

		c = a / b;
		std::cout << "a / b = " << c << std::endl;
	}

	{
		std::cout << std::endl << "----------min/max operator----------" << std::endl;
		Fixed a(20);
		Fixed b(10);

		std::cout << "before:" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min: " << Fixed::min(a, b) << std::endl;
		std::cout << "max: " << Fixed::max(a, b) << std::endl << std::endl;

		a = Fixed(1);
		b = Fixed(2);
		std::cout << "after:" << std::endl;
		std::cout << "a: " << a << ", b: " << b << std::endl;
		std::cout << "min: " << Fixed::min(a, b) << std::endl;
		std::cout << "max: " << Fixed::max(a, b) << std::endl << std::endl;

		const Fixed c(30);
		const Fixed d(40);
		std::cout << "before:" << std::endl;
		std::cout << "c: " << c << ", d: " << d << std::endl;
		std::cout << "min: " << Fixed::min(c, d) << std::endl;
		std::cout << "max: " << Fixed::max(c, d) << std::endl;

		//this cause error because c and d is const
		// c = Fixed c(1);
		// d = Fixed d(2);
	}

	{
		std::cout << std::endl << "----------increament/decreament operator----------" << std::endl;
		Fixed a(20); //this will convert to fixed number that is 20.0

		std::cout << "ori a: " << a << std::endl;
		++a; // if increase the fixed number by 1, it will be 20.00390625 mean 20.0 + 1/256 (0.00390625)
		std::cout << "pre-increament a: " << a << std::endl;
		a++; //if increase the fixed number by 1, it will be 20.0078125 mean 20.00390625 + 1/256 (0.00390625)
		std::cout << "post-increament a: " << a << std::endl;

		/**
		 * 1. why 1 / 256
		 * 	a. _fixed_point_nb is fixed point number that is 20.0.
		 * 	b. increse integer 1 to fixed point number, it will be 1 / (1 << 8) = 1 / 256 (1 had
		 *     to convert to fixed point number)
		*/
		//note: if you put "a++" in the output stream, it will print the value before increase, so make sure to print it again

	}
	return 0;
}
