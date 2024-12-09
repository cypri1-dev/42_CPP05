/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:56:14 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/09 15:19:59 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "colors.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RRF", 72, 45), _target(target) {
	std::cout << BOLD_ON << "RobotomyRequestForm default constructor called" << BOLD_OFF << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << BOLD_ON RED <<"RobotomyRequestForm destructor called" << BOLD_OFF << std::endl;
}

/*********************************************************************************************************/

const std::string &RobotomyRequestForm::getTarget()const {
	return (this->_target);
}

/*********************************************************************************************************/

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &s) {
	out << BOLD_ON GREEN <<"[SCF_NAME 📄]: " << BOLD_OFF << s.getName() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_EXEC]: " << BOLD_OFF <<s.getGradeToExecute() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_SIGN]: " << BOLD_OFF <<s.getGradeToSign() << std::endl;
	out << BOLD_ON GREEN << "[IS_SIGN]: " << BOLD_OFF << s.getIsSigned() << std::endl;
	out << BOLD_ON GREEN << "[TARGET]: " << BOLD_OFF << s.getTarget() << std::endl;
	
	return out;
}

/*********************************************************************************************************/

void RobotomyRequestForm::execute(Bureaucrat const &executor)const {
	if (this->getIsSigned() && executor.getGrade() <= this->getGradeToExecute())
		std::cout << "BRRRRRRRRRR! "<< BOLD_ON << this->getTarget() << BOLD_OFF << " has been robotomized successfully half of the time!" << std::endl;
	else {
		std::cout << BOLD_ON << "BRRRRRRRRRR! the robotomy failed!" << BOLD_OFF <<std::endl;
		throw GradeTooLowException();
	}
}