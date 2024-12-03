/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:37:05 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/03 16:38:02 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(1) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade) {
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > LOW_GRADE)
		throw GradeTooLowException();
	std::cout << "Bureaucrat custom constructor called" << std::endl;
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
	std::cout << "Bureaucrat destructor called" << std::endl;
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
	int old_grade = this->getGrade();
	
	if (old_grade + value > LOW_GRADE) {
		throw GradeTooLowException();
	}
	else {
		this->_grade++;
		std::cout << "You've been downgraded!" << std::endl;
	}	
}

void Bureaucrat::decrementGrade(int value) {
	int old_grade = this->getGrade();
	
	if (old_grade - value < MAX_GRADE) {
		throw GradeTooHighException();
	}
	else {
		this->_grade--;
		std::cout << "You lvlUP!" << std::endl;
	}	
}

/*********************************************************************************************************/

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << "[NAME]: " << b.getName() << std::endl;
	out << "[GRADE]: " << b.getGrade() << std::endl;
	
	return out;
}

/*********************************************************************************************************/

const char *Bureaucrat::GradeTooHighException::what()const throw() {
	return ("Bureaucrat grade too hight!");
}

const char *Bureaucrat::GradeTooLowException::what()const throw() {
	return ("Bureaucrat grade too low!");
}