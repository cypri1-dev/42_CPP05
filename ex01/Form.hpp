/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:44:08 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/05 16:27:49 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <string>
#include <iostream>

#define MAX_GRADE 1
#define MIN_GRADE 150
// #define MAX_GRADE_FORM 1
// #define MIN_GRADE_FORM 150

class Form {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form();
		Form(const std::string name, const int sign_lvl, const int exec_lvl);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		const std::string &getName()const;
		const int &getGradeToSign()const;
		const int &getGradeToExecute()const;
		const bool &getIsSigned()const;

		void beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what()const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what()const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const Form &f);

#endif