/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:37:11 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/03 16:40:50 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		// Test du constructeur par défaut
		Bureaucrat defaultBureaucrat;
		std::cout << defaultBureaucrat << std::endl;

		// Test du constructeur personnalisé
		Bureaucrat customBureaucrat("Alice", 1);
		std::cout << customBureaucrat << std::endl;

		// Test de la fonction decrementGrade()
		std::cout << "Decrementing grade of Alice by 1:" << std::endl;
		customBureaucrat.decrementGrade(1);
		std::cout << customBureaucrat << std::endl;
		
		// Test de la fonction incrementGrade()
		std::cout << "Incrementing grade of Alice by 1:" << std::endl;
		customBureaucrat.incrementGrade(1);
		std::cout << customBureaucrat << std::endl;


		// Test d'une exception GradeTooHighException
		std::cout << "Testing GradeTooHighException:" << std::endl;
		Bureaucrat highBureaucrat("Bob", 0); // Devrait lever une exception
		std::cout << highBureaucrat << std::endl;
	} 
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} 
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		// Test d'une exception GradeTooLowException
		std::cout << "Testing GradeTooLowException:" << std::endl;
		Bureaucrat lowBureaucrat("Charlie", 160); // Devrait lever une exception
		std::cout << lowBureaucrat << std::endl;
	} 
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	} 
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
