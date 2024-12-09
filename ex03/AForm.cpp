/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:56:04 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/09 16:59:52 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "colors.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {
	if (_gradeToExecute < MAX_GRADE || _gradeToSign < MAX_GRADE)
		throw GradeTooHighException();
	else if (_gradeToExecute > MIN_GRADE || _gradeToSign > MIN_GRADE)
		throw GradeTooLowException();
	std::cout << BOLD_ON << "AForm default constructor called" << BOLD_OFF << std::endl;
}

AForm::AForm(const std::string name, const int sign_lvl, const int exec_lvl) : _name(name), _isSigned(false), _gradeToSign(sign_lvl), _gradeToExecute(exec_lvl) {
	if (_gradeToExecute < MAX_GRADE || _gradeToSign < MAX_GRADE)
		throw GradeTooHighException();
	else if (_gradeToExecute > MIN_GRADE || _gradeToSign > MIN_GRADE)
		throw GradeTooLowException();
	std::cout << BOLD_ON YELLOW <<"AForm custom constructor called" << BOLD_OFF << std::endl;	
}

AForm::AForm(const AForm & other) : _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute()) {
	*this = other;
}

AForm & AForm::operator=(const AForm & other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {
	std::cout << BOLD_ON RED <<"AForm destructor called" << BOLD_OFF <<std::endl;
}

/*********************************************************************************************************/

const std::string &AForm::getName()const {
	return (this->_name);
}

const int &AForm::getGradeToSign()const {
	return (this->_gradeToSign);
}

const int &AForm::getGradeToExecute()const {
	return (this->_gradeToExecute);
}

const bool &AForm::getIsSigned()const {
	return (this->_isSigned);
}

/*********************************************************************************************************/

std::ostream &operator<<(std::ostream &out, const AForm &f) {
	out << BOLD_ON GREEN <<"[AFORM_NAME 📄]: " << BOLD_OFF << f.getName() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_EXEC]: " << BOLD_OFF <<f.getGradeToExecute() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_SIGN]: " << BOLD_OFF <<f.getGradeToSign() << std::endl;
	out << BOLD_ON GREEN << "[IS_SIGN]: " << BOLD_OFF << f.getIsSigned() << std::endl;
	
	return out;
}

/*********************************************************************************************************/

const char *AForm::GradeTooHighException::what()const throw() {
	return ("\033[1m\033[34mAForm 📄 grade too hight!\033[0m\n");
}

const char *AForm::GradeTooLowException::what()const throw() {
	return ("\033[1m\033[34mAForm 📄 grade too low!\033[0m\n");
}

const char *AForm::NotSignedException::what()const throw() {
	return ("\033[1m\033[34mAForm 📄 is not signed!\033[0m\n");
}

/*********************************************************************************************************/

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
	 	throw GradeTooLowException();
}
