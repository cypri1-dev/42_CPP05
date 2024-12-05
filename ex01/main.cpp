/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:43:27 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/05 17:15:54 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <exception>

int main (void) {
	
	try {
		
			{
				Bureaucrat b("Bob", 15);
				Form f("Taxes", 20, 12);
				std::cout << b << std::endl;
				std::cout << f << std::endl;

				// f.beSigned(b);
				// std::cout << f << std::endl;
				b.signForm(f);
				std::cout << f << std::endl;
			}

			{
				Bureaucrat b("Ana", 150);
				Form f("Taxes", 2, 12);
				std::cout << b << std::endl;
				std::cout << f << std::endl;

				// f.beSigned(b);
				// std::cout << f << std::endl;
				b.signForm(f);
				std::cout << f << std::endl;
			}

			{
				Form f("AnswerOfLife", 0, -1);
			}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}