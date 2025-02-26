/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:27:27 by welow             #+#    #+#             */
/*   Updated: 2025/02/24 11:47:14 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_nb(0)
{
	std::cout << BLUE_H << "Default constructor called" << RESET << std::endl;
}

/**
 * @brief convert the integer to fixed point
 * @param nb integer value to convert
 * @note 1. formula : [ nb * (1 << fractional_bit) ]
 * @note 2. EXAMPLE : [ 10 * (1 << 8) ] => [ 10 * 2^8 ] => [ 10 * 256 = 2560 ]
*/
Fixed::Fixed( int const nb ) : _fixed_point_nb(nb * (1 << Fixed::_fractional_bit))
{
	std::cout << "Int constructor called"<< std::endl;
}

/**
 * @brief convert the float to fixed point
 * @param nb float value to convert
 * @note 1. formula : [ roundf(nb * (1 << fractional_bit)) ]
 * @note 2. EXAMPLE : [ roundf(42.42 * (1 << 8)) ] => [ roundf(42.42 * 2^8) ] => [ roundf(42.42 * 256) = 10837 ]
*/
Fixed::Fixed( float const nb ) : _fixed_point_nb(roundf(nb * (1 << Fixed::_fractional_bit)))
{
	std::cout << "Float constructor called" << std::endl;
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
Fixed &Fixed::operator=( Fixed const &src)
{
	std::cout << YELLOW_H << "Copy assignment operator called" << RESET << std::endl;
	if (this != &src)
		this->_fixed_point_nb = src._fixed_point_nb;
	return *this;
}

/**
 * @brief destructor
*/
Fixed::~Fixed()
{
	std::cout << GREEN_H << "Destructor called" << RESET << std::endl;;
}

/**
 * @brief convert fixed point value to floating point value
 * @return floating point value
 * @note 1. formula : [ (float)fixed_point / 1 << fractional_bit ]
 * @note 2. EXAMPLE : 2560 that is float 10 fixed point value
 *          [ (float)2560 / 1 << 8 ] => [ 2560 / 2^8 ] => [ 2560 / 256 = 10 ]
*/
float	Fixed::toFloat( void ) const
{
	return ((float)this->_fixed_point_nb / (1 << Fixed::_fractional_bit));
}

/**
 * @brief convert fixed point value to integer value
 * @return integer value
 * @note 1. formula : [ fixed_point / 1 << fractional_bit ]
 * @note 2. EXAMPLE : 10837 that is integer 42.42 fixed point value
 * 		 [ 10837 / 1 << 8 ] => [ 10837 / 2^8 ] => [ 10837 / 256 = 42.42 ]
*/
int	Fixed::toInt( void ) const
{
	return (this->_fixed_point_nb / (1 << Fixed::_fractional_bit));
}

/**
 * @brief when "std::cout" is called, this function will be called to do other operation
 * @param output output stream
 * @param src copy of the value
 * @return output stream
 * @note it convert output to floating point value (pdf require)
*/
std::ostream	&operator<<(std::ostream &output, Fixed const &src)
{
	output << src.toFloat();
	return output;
}