/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:56:06 by cyferrei          #+#    #+#             */
/*   Updated: 2024/12/09 16:58:51 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

#include <string>

class AForm {
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		AForm();
		AForm(const std::string name, const int sign_lvl, const int exec_lvl);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		const std::string &getName()const;
		const int &getGradeToSign()const;
		const int &getGradeToExecute()const;
		const bool &getIsSigned()const;

		void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const &executor)const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what()const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what()const throw();
		};

		class NotSignedException : public std::exception {
			public:
				virtual const char *what()const throw();
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif