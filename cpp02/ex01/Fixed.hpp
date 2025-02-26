/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:27:35 by welow             #+#    #+#             */
/*   Updated: 2025/02/24 11:47:19 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

#define BLUE_H "\033[0;44m"
#define RED_H "\033[0;41m"
#define YELLOW_H "\033[0;43m"
#define GREEN_H "\033[0;42m"
#define PURPLE_H "\033[0;45m"
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
};

//* std::ostream is a class that represents the output stream
std::ostream &operator<<(std::ostream &output, Fixed const &src);

#endif