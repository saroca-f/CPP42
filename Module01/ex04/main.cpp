/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:04:09 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 11:25:14 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

// pos = str.find(old_word, i);
// Find the old_word in the string, where the first parameter is the word to find
// and the second is the position to start the search.
// If the word is found, the function returns the position of the first character 
// of the first occurrence of the word. Return npos if the word is not found.

int replace(char **argv, std::string str)
{
	std::string     old_word = argv[2];
	std::string     new_word = argv[3];
	std::ofstream	outfile;
	size_t          pos = 0;

	outfile.open((std::string(argv[1]) + ".replace").c_str());
	if (outfile.fail())
		return (1);
	for(size_t i = 0; i < str.length(); i++)
	{
		pos = str.find(old_word, i);
		if (pos != std::string::npos && pos == i)
		{
			outfile << new_word;
			i += old_word.length() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return (0);
}

int main(int argc, char **argv)
{
    char            c;
	std::string		str;
    std::ifstream	infile;

	// Parse arguments
    if (argc != 4)
	{
		std::cout << "usage: replace <file> old_word new_word" << std::endl;
		return (1);
	}
	if (argv[2][0] == '\0')
	{
		std::cout << "Error: old_word is empty." << std::endl;
		return (1);
	}
    infile.open(argv[1]);
    if (!infile.is_open())
    {
        std::cout << "Error: could not open " << argv[1] << ": Maybe no such file or directory or does not have the permissions." << std::endl;
        return (1);
    }
	// Read file and keep it in str
    while(!infile.eof() && infile >> std::noskipws >> c)
		str += c;
    infile.close();
	// Replace
    return (replace(argv, str));
}