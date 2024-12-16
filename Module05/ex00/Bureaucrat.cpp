/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:43:14 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/10 12:25:24 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("someone") , _grade(0) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->_grade = grade;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	*this = copy;
}

Bureaucrat const &Bureaucrat::operator=(Bureaucrat const &copy)
{
	this->_name = copy._name;
	this->_grade = copy._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void) {}

std::string const Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::Upgrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::Downgrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream	&operator<<(std::ostream &output, const Bureaucrat &bureaucrat)
{
	output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return output;
}