/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:02:35 by welow             #+#    #+#             */
/*   Updated: 2025/01/15 13:06:53 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point(void);
		Point(Fixed const x, Fixed const y);
		Point(Point const &src);
		~Point(void);

		Point &operator=(Point const &src);
		Fixed const &getY(void) const;
		Fixed const &getX(void) const;
};

# endif