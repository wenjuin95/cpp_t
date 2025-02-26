/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:45 by welow             #+#    #+#             */
/*   Updated: 2025/02/24 16:50:21 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iomanip>
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define CYAN "\033[36m"

void display_bot(DiamondTrap &bot1, DiamondTrap &bot2)
{
	if (bot1.getName().length() < 10)
    	std::cout << std::left << CYAN << "Name: " << RESET << bot1.getName()
              << std::setw(25) << CYAN << "Name: " << RESET << bot2.getName() << std::endl;
	else
		std::cout << std::left << CYAN << "Name: " << RESET << bot1.getName()
              << std::setw(14) << CYAN << "Name: " << RESET << bot2.getName() << std::endl;

    std::cout << std::left << GREEN << "Hit Point: " << RESET << bot1.getHitPoint();
	if (bot1.getHitPoint() >= 10)
		std::cout << std::setw(20) << GREEN << "Hit Point: " << RESET << bot2.getHitPoint() << std::endl;
	else
		std::cout << std::setw(22) << GREEN << "Hit Point: " << RESET << bot2.getHitPoint() << std::endl;

    std::cout << std::left << BLUE << "Energy Point: " << RESET << bot1.getEnergyPoint();
	if (bot1.getEnergyPoint() >= 10)
		std::cout << std::setw(18) << BLUE << "Energy Point: " << RESET << bot2.getEnergyPoint() << std::endl;
	else
		std::cout << std::setw(19) << BLUE << "Energy Point: " << RESET << bot2.getEnergyPoint() << std::endl;

    std::cout << std::left << RED << "Attack Damage: " << RESET << bot1.getAttackDamage()
              << std::setw(17) << RED << "Attack Damage: " << RESET << bot2.getAttackDamage() << std::endl;
}

int main(void)
{
	DiamondTrap bot1("d-1");
	DiamondTrap bot2("d-2");

	std::cout << "=============================================================================" << std::endl << std::endl;
	{
		DiamondTrap diamondtrap1(bot1);
		DiamondTrap diamondtrap2(bot2);

		std::cout << "diamondtrap1                 diamondtrap2" << std::endl;
		display_bot(diamondtrap1, diamondtrap2);
		std::cout << std::endl;

		std::cout << "---------- diamondtrap1 vs diamondtrap2 ---------" << std::endl;
		diamondtrap1.attack("d-2"); //claptrap::attack will be called
		display_bot(diamondtrap1, diamondtrap2);
		std::cout << std::endl;

		diamondtrap2.takeDamage(diamondtrap1.getAttackDamage()); //claptrap::takeDamage will be called
		display_bot(diamondtrap1, diamondtrap2);
		std::cout << std::endl;

		std::cout << "---------- diamondtrap ability ---------" << std::endl;
		diamondtrap1.whoAmI();
		diamondtrap2.whoAmI();
	}
	std::cout << "=============================================================================" << std::endl << std::endl;
}