/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:45 by welow             #+#    #+#             */
/*   Updated: 2025/02/07 14:13:08 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iomanip>
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define CYAN "\033[36m"

void display_bot(ScavTrap &bot1, ScavTrap &bot2)
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
	{
		ScavTrap srav1;
		ScavTrap srav2("Scavvvvvvv");
		ScavTrap srav3(srav2);

		std::cout << "scavtrap1: " << srav1.getName() << std::endl;
		std::cout << "scavtrap2: " << srav2.getName() << std::endl;
		std::cout << "scavtrap3: " << srav3.getName() << std::endl;
	}
	//these both create one "Claptrap" constructor each
	ScavTrap botA("S-1");
	ScavTrap botB("S-2"); //Claptrap constructor -> Scavtrap constructor

	{
		//this copy the "Claptrap" constructor to "Claptrap" constructor for each
		ScavTrap scavtrap = botA;
		ScavTrap scavtrap2 = botB; //Claptrap copy constuctor -> Scavtrap copy constructor

		std::cout << "SACVTRAP1                     SCAVTRAP2" << std::endl;
		display_bot(scavtrap, scavtrap2);
		std::cout << std::endl;

		std::cout << "---------- start ---------" << std::endl;
		scavtrap.attack(scavtrap2.getName());
		display_bot(scavtrap, scavtrap2);
		std::cout << std::endl;

		scavtrap2.takeDamage(scavtrap.getAttackDamage());
		display_bot(scavtrap, scavtrap2);
		std::cout << std::endl;

		scavtrap2.beRepaired(5);
		display_bot(scavtrap, scavtrap2);
		std::cout << std::endl;

		std::cout << "---------- sravtrap ability ---------" << std::endl;
		scavtrap.guardGate();
	}
	std::cout << "=======================================================================" << std::endl;
}