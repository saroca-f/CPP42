/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:10:52 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/15 18:55:39 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		virtual void	beSigned(Bureaucrat &Bureaucrat);
		void			execute(Bureaucrat const &executor) const;
		virtual void	beExecuted(Bureaucrat const &bureaucrat) const = 0;

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