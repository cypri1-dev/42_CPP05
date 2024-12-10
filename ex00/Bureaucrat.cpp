/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:37:05 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/10 13:24:21 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.hpp"


Bureaucrat::Bureaucrat() : _name("default"), _grade(1) {
	if (_grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (_grade > LOW_GRADE)
		throw GradeTooLowException();
	std::cout << BOLD_ON << "Bureaucrat default constructor called" << BOLD_OFF << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
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

unsigned int Bureaucrat::getGrade(void) const {
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

/*********************************************************************************************************/

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << BOLD_ON BLUE << b.getName() << BOLD_OFF << ", bureaucrat grade " << BOLD_ON RED << b.getGrade() << BOLD_OFF << "." << std::endl;
	
	return out;
}

/*********************************************************************************************************/

const char *Bureaucrat::GradeTooHighException::what()const throw() {
	return ("\033[1m\033[34mBureaucrat grade too hight!\033[0m");
}

const char *Bureaucrat::GradeTooLowException::what()const throw() {
	return ("\033[1m\033[34mBureaucrat grade too low!\033[0m");
}