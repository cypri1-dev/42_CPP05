/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:37:08 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/05 16:51:49 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>
#include <iostream>

#define MAX_GRADE 1
#define LOW_GRADE 150


class Form;

class Bureaucrat {
private:
	const std::string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string & name, int grade);
	Bureaucrat(const Bureaucrat & other);
	Bureaucrat & operator=(const Bureaucrat & other);
	~Bureaucrat();

	const std::string &getName(void)const;
	int getGrade(void)const ;

	void incrementGrade(int value);
	void decrementGrade(int value);

	void signForm(Form &f);

	class GradeTooHighException: public std::exception {
		public:
			virtual const char *what()const throw();
	};

	class GradeTooLowException: public std::exception {
		public:
			virtual const char *what()const throw();
	};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif