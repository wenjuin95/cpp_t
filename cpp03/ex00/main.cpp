/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:45 by welow             #+#    #+#             */
/*   Updated: 2025/02/07 14:13:46 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iomanip>

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

void display_bot(ClapTrap &bot1, ClapTrap &bot2)
{
    std::cout << std::left << CYAN << "Name: " << RESET << bot1.getName()
              << std::setw(25) << CYAN << "Name: " << RESET << bot2.getName() << std::endl;

    std::cout << std::left << GREEN << "Hit Point: " << RESET << bot1.getHitPoint();
	if (bot1.getHitPoint() >= 10)
		std::cout << std::setw(21) << GREEN << "Hit Point: " << RESET << bot2.getHitPoint() << std::endl;
	else
		std::cout << std::setw(22) << GREEN << "Hit Point: " << RESET << bot2.getHitPoint() << std::endl;

    std::cout << std::left << BLUE << "Energy Point: " << RESET << bot1.getEnergyPoint();
	if (bot1.getEnergyPoint() >= 10)
		std::cout << std::setw(18) << BLUE << "Energy Point: " << RESET << bot2.getEnergyPoint() << std::endl;
	else
		std::cout << std::setw(19) << BLUE << "Energy Point: " << RESET << bot2.getEnergyPoint() << std::endl;

    std::cout << std::left << RED << "Attack Damage: " << RESET << bot1.getAttackDamage()
              << std::setw(18) << RED << "Attack Damage: " << RESET << bot2.getAttackDamage() << std::endl;
}

int main(void)
{
	std::string bot1 = "A-1";
	std::string bot2 = "B-2";

	ClapTrap botA(bot1);
	ClapTrap botB(bot2);

	{


		ClapTrap claptrap1(botA);
		ClapTrap claptrap2(botB);

		std::cout << "CLAPTRAP1                    CLAPTRAP2" << std::endl;
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;

		claptrap1.attack(claptrap2.getName());
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;

		claptrap2.takeDamage(claptrap1.getAttackDamage());
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;

		claptrap2.beRepaired(5);
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;

	}
	std::cout << "==========================================================" << std::endl << std::endl;
	{
		ClapTrap claptrap1(botA);
		ClapTrap claptrap2(botB);

		claptrap2.attack(claptrap1.getName());
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;

		claptrap2.takeDamage(claptrap2.getAttackDamage());
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;

		claptrap2.beRepaired(5);
		display_bot(claptrap1, claptrap2);
		std::cout << std::endl;
	}
	std::cout << "=======================================================================" << std::endl;
}