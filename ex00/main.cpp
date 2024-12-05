/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:37:11 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/05 15:23:53 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	try {
			{
				Bureaucrat default_b;
				std::cout << default_b << std::endl;
			}

			{
				Bureaucrat b("Mark", 3);
				std::cout << b << std::endl;
				b.incrementGrade(2);
				std::cout << b << std::endl;
				b.decrementGrade(1);
				std::cout << b << std::endl;
			}
			
			{
				Bureaucrat b("Eve", 150);
				std::cout << b << std::endl;
				// b.decrementGrade(5);
				// std::cout << b << std::endl;
			}
			
			{
				Bureaucrat b("Toto", 1);
				std::cout << b << std::endl;
				// b.incrementGrade(1);
				// std::cout << b << std::endl;
			}
			
			{
				Bureaucrat b("Cheater", -42);
				std::cout << b << std::endl;
			}
			
	}
	catch (std::exception &e) {	
		std::cout << e.what() << std::endl;
	}
	return 0;
}
