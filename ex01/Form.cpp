/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:44:06 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/05 17:17:31 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "colors.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {
	if (_gradeToExecute < MAX_GRADE || _gradeToSign < MAX_GRADE)
		throw GradeTooHighException();
	else if (_gradeToExecute > MIN_GRADE || _gradeToSign > MIN_GRADE)
		throw GradeTooLowException();
	std::cout << BOLD_ON << "Form default constructor called" << BOLD_OFF << std::endl;
}

Form::Form(const std::string name, const int sign_lvl, const int exec_lvl) : _name(name + " 📄"), _isSigned(false), _gradeToSign(sign_lvl), _gradeToExecute(exec_lvl) {
	if (_gradeToExecute < MAX_GRADE || _gradeToSign < MAX_GRADE)
		throw GradeTooHighException();
	else if (_gradeToExecute > MIN_GRADE || _gradeToSign > MIN_GRADE)
		throw GradeTooLowException();
	std::cout << BOLD_ON YELLOW <<"Form custom constructor called" << BOLD_OFF << std::endl;	
}

Form::Form(const Form & other) : _gradeToSign(other.getGradeToSign()), _gradeToExecute(other.getGradeToExecute()) {
	*this = other;
}

Form & Form::operator=(const Form & other) {
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {
	std::cout << BOLD_ON RED <<"Form destructor called" << BOLD_OFF <<std::endl;
}

/*********************************************************************************************************/

const std::string &Form::getName()const {
	return (this->_name);
}

const int &Form::getGradeToSign()const {
	return (this->_gradeToSign);
}

const int &Form::getGradeToExecute()const {
	return (this->_gradeToExecute);
}

const bool &Form::getIsSigned()const {
	return (this->_isSigned);
}

/*********************************************************************************************************/

std::ostream &operator<<(std::ostream &out, const Form &f) {
	out << BOLD_ON GREEN <<"[FORM_NAME 📄]: " << BOLD_OFF << f.getName() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_EXEC]: " << BOLD_OFF <<f.getGradeToExecute() << std::endl;
	out << BOLD_ON GREEN << "[GRADE_SIGN]: " << BOLD_OFF <<f.getGradeToSign() << std::endl;
	out << BOLD_ON GREEN << "[IS_SIGN]: " << BOLD_OFF << f.getIsSigned() << std::endl;
	
	return out;
}

/*********************************************************************************************************/

const char *Form::GradeTooHighException::what()const throw() {
	return ("\033[1m\033[34mForm 📄 grade too hight!\033[0m\n");
}

const char *Form::GradeTooLowException::what()const throw() {
	return ("\033[1m\033[34mForm 📄 grade too low!\033[0m\n");
}

/*********************************************************************************************************/

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() <= this->_gradeToSign)
		this->_isSigned = true;
	else
	 	GradeTooLowException();
}

