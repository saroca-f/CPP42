/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:33:45 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/17 16:35:54 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", 72, 45), _target("anyone") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm::AForm(copy), _target(copy._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm const &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	AForm::operator=(copy);
	this->_target = copy._target;
	return(*this);
}

std::string const &RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::beExecuted(Bureaucrat const &bureaucrat) const
{
	int	success;

	(void) bureaucrat;
	srand((unsigned)time(NULL)); // Seed the random number generator with the current time
	success = rand() % 2; // Generate a random number (0 or 1)
	if (success)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->_target << "'s robotomization failed" << std::endl;
}

AForm	*RobotomyRequestForm::makeForm(AForm *document, std::string const &form, std::string const &target)
{
	if (document == NULL && form == "robotomy request")
	{
		return (new RobotomyRequestForm(target));
	}
	return (document);
}