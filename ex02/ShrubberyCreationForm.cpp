/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:56:20 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/09 16:05:43 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "colors.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("SCF", 145, 137), _target(target) {
	std::cout << BOLD_ON << "ShrubberyCreationForm default constructor called" << BOLD_OFF << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other.getName(), other.getGradeToSign(), other.getGradeToExecute()) {
	*this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << BOLD_ON RED <<"ShrubberyCreationForm destructor called" << BOLD_OFF << std::endl;
}

/*********************************************************************************************************/

const std::string &ShrubberyCreationForm::getTarget()const {
	return (this->_target);
}

/*********************************************************************************************************/

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &s) {
	out << BOLD_ON GREEN <<"[SCF_NAME 📄]: " << BOLD_OFF << s.getName() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_EXEC]: " << BOLD_OFF <<s.getGradeToExecute() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_SIGN]: " << BOLD_OFF <<s.getGradeToSign() << std::endl;
	out << BOLD_ON GREEN << "[IS_SIGN]: " << BOLD_OFF << s.getIsSigned() << std::endl;
	out << BOLD_ON GREEN << "[TARGET]: " << BOLD_OFF << s.getTarget() << std::endl;
	
	return out;
}

/*********************************************************************************************************/

void ShrubberyCreationForm::execute(Bureaucrat const &executor)const {
	if (this->getIsSigned() && executor.getGrade() <= this->getGradeToExecute()) {
		std::string file_name = this->getTarget() + "_shrubbery";
		if (file_name.size() == 0) {
			file_name = "default_shrubbery";
		}
		std::ofstream file(file_name.c_str());
		if (file.is_open()) {
			file << "       |\n";
			file << "      /|\\\n";
			file << "     //|\\\\\n";
			file << "    ///|\\\\\\\n";
			file << "   ////|\\\\\\\\\n";
			file << "  /////|\\\\\\\\\\\n";
			file << " //////|\\\\\\\\\\\\\n";
			file << "        ||\n";
			file << "        ||\n";
			file << "       ==== \n";
		}
		file.close();
	}
	else {
		throw GradeTooLowException();
	}
}