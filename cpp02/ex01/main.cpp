/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:24:32 by welow             #+#    #+#             */
/*   Updated: 2025/02/24 11:14:46 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed	a;
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	//convert fixed to float because the operator(<<) overloaded
	std::cout << std::endl << "---------- fixed to float ----------" << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	//convert the fixed to integer
	std::cout << std::endl << "---------- fixed to int ---------" << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}