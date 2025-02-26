/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:28:37 by welow             #+#    #+#             */
/*   Updated: 2025/02/07 14:19:36 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

#define YELLOW_H "\033[43m"
#define RESET "\033[0m"

class FragTrap : virtual public ClapTrap
{
    protected:
        static unsigned int const _initHitPoint = 100;
        static unsigned int const _initEnergyPoint = 100;
        static unsigned int const _initAttackDamage = 30;
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap &src);
        FragTrap    &operator=(const FragTrap &src);
        ~FragTrap(void);
        void    highFiveGuys(void);
};

#endif