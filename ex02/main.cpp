/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:32:20 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/06 16:55:26 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main (void) {
	AForm test;
	std::cout << test << std::endl << std::endl;

	ShrubberyCreationForm s("Toto");
	std::cout << s << std::endl;

	RobotomyRequestForm r("Brakis");
	std::cout << r << std::endl;

	PresidentialPardonForm p("Cousto");
	std::cout << p << std::endl;
	
	return (0);
}