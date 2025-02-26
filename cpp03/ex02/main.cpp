/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welow <welow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:45 by welow             #+#    #+#             */
/*   Updated: 2025/02/07 14:12:53 by welow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include <iomanip>
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define CYAN "\033[36m"

void display_bot(FragTrap &bot1, FragTrap &bot2)
{
    std::cout << std::left << CYAN << "Name: " << RESET << bot1.getName()
              << std::setw(26) << CYAN << "Name: " << RESET << bot2.getName() << std::endl;

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
	FragTrap botA("F-1");
	FragTrap botB("F-2");

	{
		FragTrap fragtrap(botA);
		FragTrap fragtrap2(botB);

		std::cout << "FRAGTRAP1                     FRAGTRAP2" << std::endl;
		display_bot(fragtrap, fragtrap2);
		std::cout << std::endl;

		std::cout << "---------- start ----------" << std::endl;
		fragtrap.attack(fragtrap2.getName());
		display_bot(fragtrap, fragtrap2);
		std::cout << std::endl;

		fragtrap2.takeDamage(fragtrap.getAttackDamage());
		display_bot(fragtrap, fragtrap2);
		std::cout << std::endl;

		fragtrap2.beRepaired(5);
		display_bot(fragtrap, fragtrap2);
		std::cout << std::endl;

		std::cout << "---------- fragtrap ability ----------" << std::endl;
		fragtrap.highFiveGuys();
	}
	std::cout << "=============================================================================" << std::endl << std::endl;
}