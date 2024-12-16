/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:37:49 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/17 16:36:39 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern const &Intern::operator=(Intern const &copy)
{
	(void)copy;
	return (*this);
}

AForm *Intern::makeForm(std::string const &form, std::string const &target)
{
	AForm *document;
	
	document = AForm::makeForm(form, target);
	if (!document)
		throw FormNoExist();
	std::cout << "Intern creates form: " << form << " with target: " << document->getTarget() << std::endl;
	return (document);
}

char const *Intern::FormNoExist::what() const throw()
{
	return("This form donnot exist");
}