/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:38:40 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/17 16:36:00 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentialPardonForm", 25, 5), _target("anyone") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm::AForm(copy), _target(copy._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

AForm	*PresidentialPardonForm::makeForm(AForm *document, std::string const &form, std::string const &target)
{
	if (document == NULL && form == "presidential pardon")
	{
		return (new PresidentialPardonForm(target));
	}
	return (document);
}

PresidentialPardonForm const &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return(*this);
}

std::string const &PresidentialPardonForm::getTarget() const
{
	return(this->_target);
}

void PresidentialPardonForm::beExecuted(Bureaucrat const &bureaucrat) const
{
	(void)bureaucrat;
    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}