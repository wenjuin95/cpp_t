/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:16:48 by welow             #+#    #+#             */
/*   Updated: 2025/02/24 11:39:46 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @breif default constructor
 * @note 1. setter:
 * 			pros:
 * 				1. making code easy to maintian
 * 				2. if the logic for the setter changed, only change the function
 * 			cons:
 * 				1. less efficient duw to another function call
 * 				2. poor readability
 * 		2. initialize list:
 * 			pros:
 * 				1. more efficient because no function call
 * 				2. easy read
 * 			cons:
 * 				1. if the logic for the setter changed, need to change the constructor
*/
Fixed::Fixed(void)
{
	std::cout << BLUE_H << "Default constructor called" << RESET << std::endl;
	this->setRawBits(0);
}

/**
 * @brief copy constructor
 * @param src source to copy
 * @note "*this" is a pointer to the object itself
*/
Fixed::Fixed(const Fixed &src)
{
	std::cout << RED_H << "Copy constructor called" << RESET << std::endl;
	*this = src;
}

/**
 * @brief assignment operator
 * @param src source to assign
 * @return *this
 * @note 1. if the source is not same with this object, copy the source to this object
 * @note 2. we change fixed number because fractional number always the same (because constant)
 * @note 3. "&" in return type is to return the reference of the object itself. this
 *          avoid the object to be copied ( allow to chain multiple assignment)
*/
Fixed& Fixed::operator=( Fixed const &src)
{
	std::cout << YELLOW_H << "Copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->_fixed_point_nb = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << GREEN_H << "Destructor called" << RESET << std::endl;
}

void	Fixed::setRawBits( int const fixed_point_nb )
{
	this->_fixed_point_nb = fixed_point_nb;
}

int	Fixed::getRawBits( void ) const
{
	std::cout << PURPLE_H << "getRawBits member function called" << RESET << std::endl;
	return this->_fixed_point_nb;
}

