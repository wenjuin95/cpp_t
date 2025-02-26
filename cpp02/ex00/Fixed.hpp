/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:31:26 by welow             #+#    #+#             */
/*   Updated: 2025/02/19 17:34:03 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
		Fixed(const Fixed &src);
		Fixed &operator=(const Fixed &src);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const fixed_point_nb);
};

#endif