/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:56:10 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/06 16:54:34 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "colors.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PPF", 25, 5), _target(target) {
	std::cout << BOLD_ON << "PresidentialPardonForm default constructor called" << BOLD_OFF << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {
	*this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << BOLD_ON RED <<"PresidentialPardonForm destructor called" << BOLD_OFF << std::endl;
}

/*********************************************************************************************************/

const std::string &PresidentialPardonForm::getTarget()const {
	return (this->_target);
}

/*********************************************************************************************************/

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &s) {
	out << BOLD_ON GREEN <<"[SCF_NAME 📄]: " << BOLD_OFF << s.getName() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_EXEC]: " << BOLD_OFF <<s.getGradeToExecute() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_SIGN]: " << BOLD_OFF <<s.getGradeToSign() << std::endl;
	out << BOLD_ON GREEN << "[IS_SIGN]: " << BOLD_OFF << s.getIsSigned() << std::endl;
	out << BOLD_ON GREEN << "[TARGET]: " << BOLD_OFF << s.getTarget() << std::endl;
	
	return out;
}