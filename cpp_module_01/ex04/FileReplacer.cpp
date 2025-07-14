/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:36:41 by meid              #+#    #+#             */
/*   Updated: 2025/07/14 15:56:23 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

FileReplacer::FileReplacer(std::string fileName, std::string toFind, std::string  toReplace)
        : _fileName(fileName), _toFind(toFind), _toReplace(toReplace),  _outFile(fileName + ".replace") {}

FileReplacer::~FileReplacer() {}


std::string FileReplacer::check_line_and_change(std::string *linee)
{
    std::string line = *linee;
    
    int start = -1;
    int end = -1;
    int j = 0;
    for (int i = 0; line[i]; i++)
    { 
        if (line[i] == _toFind[0])
        {
            j = 0;
            start = i;
            while (line[i] && _toFind[j] && line[i] == _toFind[j])
            {
                j++;
                i++;
            }
            end = i - 1;
            i--;
            if (_toFind[j] == '\0')
            {
                std::string new_line = change_line(line, &i, start, end);
                line = new_line;
            }
        }   
    }
    return (line);
}

bool FileReplacer::openFiles(std::ifstream& in, std::ofstream& out)
{
    if (!in.is_open() || !out.is_open())
    {
        std::cerr << "Error: could not open input or output file." << std::endl;
        return false;
    }
	else if (in.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "Input file is empty!" << std::endl;
		return false;
	}
    return true;
}

bool  FileReplacer::emptyreplace()
{
	std::cout << YELLOW << "Warning: All occurrences of '" << _toFind 
	<< "' will be deleted from the file." << RESET << std::endl;

	std::string decision;
	std::cout << BLUE << "Do you want to proceed? yes/no: ";

	if (!(std::cin >> decision)) {
		std::cout << RESET << std::endl
			<< RED << "Input interrupted. Aborting..." << RESET << std::endl;
		return false;
	}

	if (decision == "no") {
		std::cout << YELLOW << "Respecting your decision." << RESET << std::endl;
		return false;
	}

	if (decision != "yes") {
		std::cout << YELLOW
			<< "I asked for yes or no. I didn’t want to stop the program this way,\n"
			<< "but you forced me. Goodbye." << RESET << std::endl;
		return false;
	}
	return true;
}

bool FileReplacer::replacerBotton()
{
	if (_toReplace.empty()) {
		if (!emptyreplace())
			return false;
	}	
    std::ifstream file(_fileName.c_str());  // C++98: pass C-style string
    std::ofstream out(_outFile.c_str(), std::ios::out | std::ios::trunc);

    if (!openFiles(file, out))
        return false;

	std::string line;
	std::string new_line;
	while (getline (file, line)) {
		new_line = check_line_and_change(&line);
		out << new_line << std::endl;
	}
    out.close();

    return true;
}

std::string    FileReplacer::change_line(std::string line, int *i, int start, int end)
{
    std::string result;
    result += line.substr(0, start);
    result += _toReplace;
    result += line.substr(end + 1);
    *i = start + _toReplace.length() - 1;
    return (result);
}