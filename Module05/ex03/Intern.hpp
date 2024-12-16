/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:37:24 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/17 15:34:00 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern() {};
		Intern(Intern const &copy);
		~Intern() {};
		Intern const &operator=(Intern const &copy);
		AForm *makeForm(std::string const &form, std::string const &target);

		class FormNoExist : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};