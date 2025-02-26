/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:36:46 by welow             #+#    #+#             */
/*   Updated: 2025/02/07 13:59:18 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap("F-DEFAULT")
{
    if (CALL == 1)
        std::cout << YELLOW_H << "FragTrap (default constructor) called" << RESET << std::endl;
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    if (CALL == 1)
        std::cout << YELLOW_H << "FragTrap (constructor) called" << RESET << std::endl;
    this->_name = name;
    this->_hitPoint = 100;
    this->_energyPoint = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
    if (CALL == 1)
        std::cout << YELLOW_H << "FragTrap (copy constructor) called" << RESET << std::endl;
    *this = src;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    if (CALL == 1)
        std::cout << YELLOW_H << "FragTrap (assignment operator) called" << RESET << std::endl;
    if (this != &src)
    {
        this->_name = src._name;
        this->_hitPoint = src._hitPoint;
        this->_energyPoint = src._energyPoint;
        this->_attackDamage = src._attackDamage;
    }
    return (*this);
}

FragTrap::~FragTrap(void)
{
    if (CALL == 1)
        std::cout << YELLOW_H << "FragTrap (destructor) called" << RESET << std::endl;
}

void    FragTrap::highFiveGuys(void)
{
    if (this->_hitPoint == 0)
        std::cout << "FragTrap [" << this->_name << "] already dead" << std::endl;
    else
        std::cout << "FragTrap [" << this->_name << "] high five" << std::endl;
}