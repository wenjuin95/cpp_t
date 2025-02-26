/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:51:23 by welow             #+#    #+#             */
/*   Updated: 2025/02/07 11:19:25 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//initialize the base class constructor to prevent undefined behavior
ScavTrap::ScavTrap(void) : ClapTrap("S-Default")
{
	if (CALL == 1)
		std::cout << RED_H << "ScavTrap (default constructor) called" << RESET << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	if (CALL == 1)
		std::cout << RED_H << "ScavTrap (constructor) called" << RESET << std::endl;
	this->_name = name;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src)
{
	if (CALL == 1)
		std::cout << RED_H << "ScavTrap (copy constructor) called" << RESET << std::endl;
	*this = src;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	if (CALL == 1)
		std::cout << RED_H << "ScavTrap (assignment operator) called" << RESET << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		this->_hitPoint = src._hitPoint;
		this->_energyPoint = src._energyPoint;
		this->_attackDamage = src._attackDamage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	if (CALL == 1)
		std::cout << RED_H << "ScavTrap (destructor) called" << RESET << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if ( this->_energyPoint > 0 && this->_hitPoint > 0)
	{
		this->_energyPoint--;
		std::cout << "ScavTrap [" << this->_name << "] attacks [" << target
				<< "], causing [" << this->_attackDamage
				<< "] point of damage!" << std::endl;
	}
	else if (this->_energyPoint == 0)
		std::cout <<  "ScavTrap [" << this->_name << "] can't attack because [" << this->_energyPoint << "] energy point" << std::endl;
	else if (this->_hitPoint == 0)
		std::cout <<  "ScavTrap [" << this->_name << "] already dead, can't attack" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if (this->_hitPoint == 0)
		std::cout <<  "ScavTrap [" << this->_name << "] is already dead, can't guard the gate" << std::endl;
	else
		std::cout <<  "ScavTrap [" << this->_name << "] is now in Gate keeper mode" << std::endl;
}