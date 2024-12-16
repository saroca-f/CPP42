/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:10:35 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/16 15:35:12 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(0),  _gradeToSign(150) ,_gradeToExecute(150) {}

AForm::AForm(std::string name, int const signgrade, int const executegrade) : _name(name), _signed(0), _gradeToSign(signgrade), _gradeToExecute(executegrade)
{
	if (_gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150)
		throw GradeTooLowException();
	if (_gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {};

AForm const &AForm::operator=(AForm const &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

std::string const &AForm::getName() const
{
	return(this->_name);
}

std::string const AForm::getIsSigned() const
{
	if (this->_signed == true)
		return ("YES");
	return ("NO");
}

int const &AForm::getSignGrade() const
{
	return (this->_gradeToSign);
}

int const &AForm::getExecGrade() const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_signed = 1;
		std::cout << this->_name << " be signed by " << Bureaucrat.getName() << std::endl;
	}
	else
		throw GradeTooHighException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
		throw FormNoSigned();
	else if (executor.getGrade() > this->_gradeToExecute)
		throw GradeTooLowException();
	else
	{
		std::cout << executor.getName() << " executes form: " << this->_name << std::endl;
		this->beExecuted(executor);
	}
}

char const *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

char const *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

char const *AForm::FormNoSigned::what() const throw()
{
	return ("Form no signed");
}

std::ostream &operator<<(std::ostream &output, AForm const &form)
{
	return (output << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}