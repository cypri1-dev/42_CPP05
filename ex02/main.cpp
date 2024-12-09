/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:32:20 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/09 17:32:26 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main (void) {

	try {

		// TEST WITH WRONG VALUE
		// Bureaucrat cheater("cheater", -42);

		// PRESIDENTIAL PARDON FORM : S[25] | EX[5]
		// ROBOTOMY REQUEST FORM : S[72] | EX[45]
		// SHRUBBERY CREATION FORM : S[145] | EX[137]
		
		Bureaucrat brakis("Brakis", 1);
		Bureaucrat ama("Ama", 44);
		Bureaucrat titi("titi", 148);

		PresidentialPardonForm p("Toto");
		RobotomyRequestForm r("Warrox");
		ShrubberyCreationForm s("Robin");
		
		// VALID TEST SIGN + EXEC
		ama.signForm(s);
		brakis.executeForm(s);

		// TEST NOT SIGNED + EXEC OK
		// titi.signForm(p);
		// brakis.executeForm(p);

		// TEST SIGNED + NO EXEC
		// ama.signForm(r);
		// titi.executeForm(r);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return (0);
}