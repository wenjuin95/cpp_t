/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:28:37 by welow             #+#    #+#             */
/*   Updated: 2025/02/07 13:59:25 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAPTRAP_HPP
#define FRAPTRAP_HPP

#include "ScavTrap.hpp"

#define YELLOW_H "\033[43m"
#define RESET "\033[0m"

class FragTrap : public ClapTrap
{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &src);
        FragTrap    &operator=(const FragTrap &src);
        ~FragTrap(void);
        void    highFiveGuys(void);
};

#endif