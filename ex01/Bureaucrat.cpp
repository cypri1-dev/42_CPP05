/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:37:05 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/05 17:14:49 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.hpp"

#include "Form.hpp"


Bureaucrat::Bureaucrat() : _name("default"), _grade(1) {
	if (_grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (_grade > LOW_GRADE)
		throw GradeTooLowException();
	std::cout << BOLD_ON << "Bureaucrat default constructor called" << BOLD_OFF << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name + " 🙍‍♂️"), _grade(grade) {
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > LOW_GRADE)
		throw GradeTooLowException();
	std::cout << BOLD_ON YELLOW <<"Bureaucrat custom constructor called" << BOLD_OFF << std::endl;
}


Bureaucrat::Bureaucrat(const Bureaucrat & other) {
	*this = other;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat & other) {
	if (this != &other) {
		this->_grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << BOLD_ON RED <<"Bureaucrat destructor called" << BOLD_OFF <<std::endl;
}

/*********************************************************************************************************/

const std::string &Bureaucrat::getName(void)const {
	return (this->_name);
}

int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

/*********************************************************************************************************/

void Bureaucrat::incrementGrade(int value) {
	int new_grade = this->getGrade() - value;
	
	if (new_grade < MAX_GRADE) {
		throw GradeTooHighException();
	}
	else {
		this->_grade -= value;
		std::cout << "You lvlUP!" << std::endl;
	}	
}

void Bureaucrat::decrementGrade(int value) {
	int new_grade = this->getGrade() + value;
	
	if (new_grade > LOW_GRADE) {
		throw GradeTooLowException();
	}
	else {
		this->_grade += value;
		std::cout << "You've been downgraded!" << std::endl;
	}	
}

void	Bureaucrat::signForm(Form &f){
	f.beSigned(*this);
	if (f.getIsSigned() == true)
		std::cout << BOLD_ON BLUE << this->getName() << BOLD_OFF << " signed " << BOLD_ON YELLOW << f.getName() << BOLD_OFF << std::endl;
	else
		std::cout << BOLD_ON BLUE << this->getName() << BOLD_OFF << " couldn't sign " << BOLD_ON YELLOW << f.getName() << BOLD_OFF << " because grade is too low!" << std::endl;
}

/*********************************************************************************************************/

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << BOLD_ON GREEN <<"[NAME 🙍‍♂️]: " << BOLD_OFF << b.getName() << std::endl;
	out << BOLD_ON GREEN << "[GRADE]: " << BOLD_OFF <<b.getGrade() << std::endl;
	
	return out;
}

/*********************************************************************************************************/

const char *Bureaucrat::GradeTooHighException::what()const throw() {
	return ("\033[1m\033[34mBureaucrat 🙍‍♂️ grade too hight!\033[0m");
}

const char *Bureaucrat::GradeTooLowException::what()const throw() {
	return ("\033[1m\033[34mBureaucrat 🙍‍♂️ grade too low!\033[0m");
}