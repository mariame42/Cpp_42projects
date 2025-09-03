/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer_error.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:26:44 by meid              #+#    #+#             */
/*   Updated: 2025/07/16 22:27:52 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

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
	else if (isTooLarge(_fileName))
	{
		std::cerr << RED << "Error: File is too large to process." << RESET << std::endl;
		return false;
	}
	return true;
}


bool FileReplacer::isTooLarge(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);  // Open in binary mode and move to the end
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }

    // Get the size by using tellg()
    std::streamsize fileSize = file.tellg();

    // Check if the file size is greater than 100 MB
    if (fileSize > 100 * 1024 * 1024)
    {
        return true;  // File is too large
    }
    return false;  // File size is within the limit
}


bool  FileReplacer::emptyreplace()
{
	std::cout << YELLOW << "Warning: All occurrences of '" << _toFind 
	<< "' will be deleted from the file." << RESET << std::endl;

	std::string decision;
	std::cout << BLUE << "Do you want to proceed? yes/no: ";

	if (!(std::cin >> decision)) {
		std::cerr << RESET << std::endl
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

bool  FileReplacer::emptytofind()
{
	std::cout << YELLOW << "Warning: I will not change any thing there is no point " << RESET << std::endl;

	std::string decision;
	std::cout << BLUE << "Do you want to proceed? yes/no: ";

	if (!(std::cin >> decision)) {
		std::cerr << RESET << std::endl
			<< RED << "Input interrupted. Aborting..." << RESET << std::endl;
		return false;
	}

	if (decision == "no") {
		std::cout << YELLOW << "great" << RESET << std::endl;
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