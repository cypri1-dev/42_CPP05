/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:32:20 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/09 16:05:01 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main (void) {

	try {
		Bureaucrat b("Brakis", 1);
		// PresidentialPardonForm p("Toto");
		// RobotomyRequestForm r("Warrox");
		ShrubberyCreationForm s("Robin");

		std::cout << b << std::endl;
		// std::cout << p << std::endl;
		std::cout << s << std::endl;


		b.signForm(s);
		s.execute(b);
		
		// ShrubberyCreationForm s("Toto");
		// std::cout << s << std::endl;

		// RobotomyRequestForm r("Brakis");
		// std::cout << r << std::endl;

		// PresidentialPardonForm p("Cousto");
		// std::cout << p << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}