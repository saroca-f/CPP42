/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:10:52 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/15 13:44:41 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

class Bureaucrat;

class Form {
	private:
		std::string _name;
		bool _signed;
		int const _gradeToSign;
		int const _gradeToExecute;
	public:
		Form();
		Form(std::string name, int const signgrade, int const executegrade);
		~Form();
		Form const &operator=(Form const &copy);
		std::string const &getName() const;
		std::string const getIsSigned() const;
		int const &getSignGrade() const;
		int const &getExecGrade() const;
		void	beSigned(Bureaucrat &Bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, Form const &form);