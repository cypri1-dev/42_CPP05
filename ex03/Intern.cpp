/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:13:35 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/09 23:11:55 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "colors.hpp"

Intern::Intern() {
	std::cout << BOLD_ON << "Intern default constructor called" << BOLD_OFF << std::endl;
}

Intern::Intern(const Intern &other) {
	*this = other;
}

Intern &Intern::operator=(const Intern &other) {
	if (this != &other) {
		;
	}
	return (*this);
}

Intern::~Intern() {
	std::cout << BOLD_ON RED <<"Intern destructor called" << BOLD_OFF << std::endl;
}

/*********************************************************************************************************/

AForm* Intern::makeForm(std::string form_name, std::string target) {
	static const struct
	{
		std::string keyword;
		int form_case;
	}
	selection[] =
	{
		{.keyword = "presidential pardon", .form_case = 0},
		{.keyword = "robotomy request", .form_case = 1},
		{.keyword = "shrubbery creation", .form_case = 2},
	};

	for (size_t i = 0; i < NB_FORM; i++) {
		if (form_name == selection[i].keyword) {
			switch (selection[i].form_case) {
				case 0:
					std::cout << "Intern creates " << form_name << std::endl;
					return new PresidentialPardonForm(target);
				case 1:
					std::cout << "Intern creates " << form_name << std::endl;
					return new RobotomyRequestForm(target);
				case 2:
					std::cout << "Intern creates " << form_name << std::endl;;
					return new ShrubberyCreationForm(target);
				default:
					break;
			}
		}
	}
	std::cout << "Intern failed to create this unknown form: " << form_name << std::endl;
	return (NULL);
}