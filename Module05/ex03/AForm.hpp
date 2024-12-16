/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:10:52 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/17 15:40:33 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

#ifndef AFORM_HPP
# define AFORM_HPP

class Bureaucrat;

class AForm {
	private:
		std::string const _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;
	public:
		AForm();
		AForm(std::string name, int const signgrade, int const executegrade);
		virtual ~AForm();
		AForm const &operator=(AForm const &copy);
		std::string const	&getName() const;
		std::string const	getIsSigned() const;
		int const 		&getSignGrade() const;
		int const 		&getExecGrade() const;
		virtual std::string const	&getTarget() const = 0;
		virtual void	beSigned(Bureaucrat &Bureaucrat);
		void			execute(Bureaucrat const &executor) const;
		virtual void	beExecuted(Bureaucrat const &bureaucrat) const = 0;
		static AForm	*makeForm(std::string const &form, std::string const &target);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class FormNoSigned : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, AForm const &form);

#endif