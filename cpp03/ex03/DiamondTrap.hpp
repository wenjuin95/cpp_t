/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:37:00 by welow             #+#    #+#             */
/*   Updated: 2025/02/24 16:49:51 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#define BLUE_H "\033[44m"
#define RESET "\033[0m"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap &src);
        DiamondTrap &operator=(const DiamondTrap &src);
        ~DiamondTrap(void);
        using   ScavTrap::attack;
        using   FragTrap::_hitPoint;
        using   ScavTrap::_energyPoint;
        using   FragTrap::_attackDamage;
        void    whoAmI(void);
};

#endif