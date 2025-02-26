/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:40:46 by welow             #+#    #+#             */
/*   Updated: 2025/02/07 14:19:34 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#define RED_H "\033[41m"
#define RESET "\033[0m"

class ScavTrap : virtual public ClapTrap
{
	protected:
		static unsigned int const _initHitPoint = 100;
		static unsigned int const _initEnergyPoint = 50;
		static unsigned int const _initAttackDamage = 20;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &src);
		ScavTrap &operator=(const ScavTrap &src);
		~ScavTrap(void);
		void attack(std::string const &target);
		void guardGate(void);
};

#endif