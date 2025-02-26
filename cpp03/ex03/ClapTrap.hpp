/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:27:47 by welow             #+#    #+#             */
/*   Updated: 2025/02/24 15:37:19 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef CALL
#define CALL 0
#endif

class ClapTrap
{
	//change to protected
	//protected: mean that the member is accessible from the class itself and its derived classes
	private:
		static unsigned int const	_initHitPoint = 10;
		static unsigned int const	_initEnergyPoint = 10;
		static unsigned int const	_initAttackDamage = 0;
	protected:
		std::string		_name;
		unsigned int	_hitPoint;
		unsigned int	_energyPoint;
		unsigned int	_attackDamage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &src);
		ClapTrap &operator=(const ClapTrap &src);
		~ClapTrap(void);
		virtual void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		std::string		getName(void) const;
		unsigned int	getHitPoint(void) const;
		unsigned int	getEnergyPoint(void) const;
		unsigned int	getAttackDamage(void) const;
};