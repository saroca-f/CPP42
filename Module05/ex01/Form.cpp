/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:10:35 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/15 13:45:31 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _signed(0),  _gradeToSign(150) ,_gradeToExecute(150) {}

Form::Form(std::string name, int const signgrade, int const executegrade) : _name(name), _signed(0), _gradeToSign(signgrade), _gradeToExecute(executegrade)
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

Form::~Form() {};

Form const &Form::operator=(Form const &copy)
{
	this->_signed = copy._signed;
	return (*this);
}

std::string const &Form::getName() const
{
	return(this->_name);
}

std::string const Form::getIsSigned() const
{
	if (this->_signed == true)
		return ("YES");
	return ("NO");
}

int const &Form::getSignGrade() const
{
	return (this->_gradeToSign);
}

int const &Form::getExecGrade() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_signed = 1;
	}
	else
		throw GradeTooHighException();
}

char const *Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

char const *Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &output, Form const &form)
{
	return (output << form.getName() << " form, signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}