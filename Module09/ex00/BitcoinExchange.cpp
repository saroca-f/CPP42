/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:30:23 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/13 19:22:35 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static void keyBuild(std::string &key)
{
	size_t i = 0;
	int j = key.length() - 1;

	while(i < key.length() && std::isspace(key[i]))
		i++;
	while(j >= 0 && std::isspace(key[j]))
		j--;
	key = key.substr(i, j - i + 1);
}

static void valueBuild(std::string &strValue)
{
	int i = 0;
	int j = strValue.length();

	while(std::isspace(strValue[i]))
		i++;
	while(std::isspace(strValue[j]))
		j--;
	strValue = strValue.substr(i, j);
}

static bool stringToDouble(double &value, std::string &strValue)
{
	std::stringstream ss(strValue);
	ss >> value;
	if (ss.fail() || !ss.eof())
		return (false);
	if (value < 0.0)
		throw std::runtime_error(BOLD_RED "not a positive number" RESET);
	if (value > std::numeric_limits<int>::max())
		throw std::runtime_error(BOLD_RED "too large number" RESET);
    return true;
}

static void dataConstructor(std::map<std::string, double> &Prices, std::string FileName)
{
	std::ifstream File(FileName.c_str());
	std::string Line;
	if(!File.is_open())
		throw std::runtime_error("Could not open the file " BOLD_RED + FileName + RESET);
	while (std::getline(File, Line))
	{
		if(Line.empty())
			continue;
		bool int_control = false;
		for (std::string::iterator it = Line.begin(); it != Line.end(); ++it)
		{
			if (std::isdigit(*it))
				int_control = true;
		}
		if(int_control == false)
			continue;
		std::stringstream ss(Line);
        std::string key;
        std::getline(ss, key, ',');
        std::string strValue;
        std::getline(ss, strValue);
		try
		{
			keyBuild(key);
			valueBuild(strValue);
			double value;
			stringToDouble(value, strValue);
            Prices[key] = value;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED " Error: " YELLOW << e.what() << "." RESET << std::endl;
		}
			
	}
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int year, int month)
{
    switch (month)
    {
        case 1: return 31;
        case 2: return isLeapYear(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

static void dateDesgloser(int &combinedDate, std::string key)
{
	std::string s_day, s_month, s_year;
	int day, month, year;
	std::istringstream sk(key);
	
	std::getline(sk, s_year, '-'); std::getline(sk, s_month, '-'); std::getline(sk, s_day, '-');
	std::istringstream sy(s_year); std::istringstream sm(s_month); std::istringstream sd(s_day);
	sy >> year; sm >> month; sd >> day;
	if(sy.fail() || !sy.eof() || sm.fail() || !sm.eof() || sd.fail() || !sd.eof())
		throw std::runtime_error("Invalid number format: " + key);
	if (month < 1 || month > 12)
		throw std::runtime_error("invalid date: " + key);
	if (day < 1 || day > daysInMonth(year, month))
		throw std::runtime_error("invalid date: " + key);
	if (year < 2009)
		throw std::runtime_error("invalid date: " + key);
	std::ostringstream oss;
	oss << year;
	if (month < 10) 
		oss << '0';
	oss << month;
	if (day < 10) 
		oss << '0';
	oss << day;
	std::istringstream(oss.str()) >> combinedDate;
}

static void lookForCompare(std::string key, double value, std::map<std::string, double> &Prices)
{
	(void)value;
	std::map<std::string, double>::iterator it = Prices.begin();
	int ikey, idate;
	
	dateDesgloser(ikey, key);
	while(it != Prices.end())
	{
		dateDesgloser(idate, it->first);
		if (ikey <= idate)
		{
			break;
		}
		it++;
	}
	double result = value * it->second;
	std::cout << YELLOW << key << RESET " : " GREEN << result << RESET "\n";
}

static void fileCompare(std::map<std::string, double> &Prices, std::string FileName)
{
	std::ifstream File(FileName.c_str());
	std::string Line;
	double value;
	if(!File.is_open())
		throw std::runtime_error("Could not open the file " BOLD_RED + FileName + RESET);
	while (std::getline(File, Line))
	{
		if(Line.empty())
			continue;
		bool int_control = false;
		for (std::string::iterator it = Line.begin(); it != Line.end(); ++it)
		{
			if (std::isdigit(*it))
				int_control = true;
		}
		if(int_control == false)
			continue;
		std::stringstream ss(Line);
        std::string key;
        std::getline(ss, key, '|');
        std::string strValue;
        std::getline(ss, strValue);
		try
		{
			keyBuild(key);
			valueBuild(strValue);
			if (stringToDouble(value, strValue) == false)
				throw std::runtime_error("bad imput => " BOLD_RED + key + RESET);
			lookForCompare(key, value, Prices);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED "Error: " YELLOW << e.what() << "." RESET << std::endl;
		}
	}
}

void    bitcoinExchange(std::string Filename)
{
    std::map<std::string, double>	Prices;
	try
	{
    	dataConstructor(Prices, "./data.csv");
		fileCompare(Prices, Filename);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED " Error: " YELLOW << e.what() << "." RESET << std::endl; 
		return ;
	}
}