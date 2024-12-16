/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:36:45 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/17 15:42:22 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		~PresidentialPardonForm();
		PresidentialPardonForm const &operator=(PresidentialPardonForm const &copy);
		std::string const &getTarget() const;
		void beExecuted(Bureaucrat const &Bureaucrat) const;
		static AForm	*makeForm(AForm *document, std::string const &form, std::string const &target);
};