/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 07:51:45 by welow             #+#    #+#             */
/*   Updated: 2025/02/24 16:57:05 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/**
 * 1. DiamondTrap inherits from both FragTrap and ScavTrap.
 * 2. Both FragTrap and ScavTrap inherit from ClapTrap, so two copies of
 *    ClapTrap exist in DiamondTrap.
 * 3. Now, DiamondTrap has two separate _hitPoint variables, one from ScavTrap
 *    and one from FragTrap.
 *
 * When you try to access _hitPoint in DiamondTrap, the compiler does not know
 * which one you mean, leading to the "ambiguous" error.
 *
 * SOLVE: implement "virtual inheritance" in FragTrap and ScavTrap class
 * "virtual inheritance" : Only one shared copy of ClapTrap
*/
DiamondTrap::DiamondTrap(void)
    : ClapTrap("C-default"),
    FragTrap("F-default"),
    ScavTrap("S-default")
{
    if (CALL == 1)
        std::cout << BLUE_H << "DiamondTrap (default constructor) called" << RESET << std::endl;
}

/**
 * @brief a constructor
 * @param name name of object
 * @note 1. Claptrap name must + "_clap_name" (pdf require)
*/
DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name),
    FragTrap(name),
    ScavTrap(name)
{
    if (CALL == 1)
    {
        std::cout << BLUE_H << "DiamondTrap (constructor) called" << RESET << std::endl;
    }
    std::cout << "hitPoint: " << FragTrap::_hitPoint << std::endl; 
    std::cout << "energyPoint: " << ScavTrap::_energyPoint << std::endl;
    std::cout << "attackDamage: " << FragTrap::_attackDamage << std::endl;
    
    ClapTrap::_name = name + "_clap_name";
	this->_name = name;
    this->_hitPoint = FragTrap::_hitPoint;
    this->_energyPoint = ScavTrap::_energyPoint;
    this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
    : ClapTrap(src),
    FragTrap(src),
    ScavTrap(src)
{
    if (CALL == 1)
        std::cout << BLUE_H << "DiamondTrap (copy constructor) called" << RESET << std::endl;
    *this = src;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
    if (CALL == 1)
		std::cout << BLUE_H << "DiamondTrap (assignment operator) called" << RESET << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoint = src._hitPoint;
		this->_energyPoint = src._energyPoint;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
    if (CALL == 1)
        std::cout << BLUE_H << "DiamondTrap (destructor) called" << RESET << std::endl;
}


void    DiamondTrap::whoAmI(void)
{
    if (this->_hitPoint == 0)
		std::cout <<  "DiamondTrap [" << this->_name << "] is already dead" << std::endl;
	else
		std::cout <<  "DiamondTrap is [" << this->_name << "] and Claptrap is [" << ClapTrap::_name << "]" << std::endl;
}
