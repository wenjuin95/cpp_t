/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:22:35 by welow             #+#    #+#             */
/*   Updated: 2025/02/24 12:28:14 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#ifndef CALL
#define CALL 0
#endif

#define BLUE_H "\033[0;44m"
#define RED_H "\033[0;41m"
#define YELLOW_H "\033[0;43m"
#define GREEN_H "\033[0;42m"
#define PURPLE_H "\033[0;45m"
#define CYAN "\033[0;36m"
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0;37m"

class Fixed
{
	private:
		int					_fixed_point_nb;
		static const int	_fractional_bit = 8;
	public:
		Fixed(void);
		Fixed(int const nb);
		Fixed(float const nb);
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed(void);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(Fixed const &src) const;
		bool	operator<(Fixed const &src) const;
		bool	operator>=(Fixed const &src) const;
		bool	operator<=(Fixed const &src) const;
		bool	operator==(Fixed const &src) const;
		bool	operator!=(Fixed const &src) const;

		Fixed	operator+(Fixed const &src) const;
		Fixed	operator-(Fixed const &src) const;
		Fixed	operator*(Fixed const &src) const;
		Fixed	operator/(Fixed const &src) const;

		Fixed	operator++(void);
		Fixed	operator++(int);
		Fixed	operator--(void);
		Fixed	operator--(int);

		static Fixed 		&min( Fixed &a, Fixed &b );
		static Fixed const	&min( Fixed const &a, Fixed const &b );
		static Fixed		&max( Fixed &a, Fixed &b );
		static Fixed const	&max( Fixed const &a, Fixed const &b );
};

std::ostream &operator<<(std::ostream &output, Fixed const &src);

#endif
