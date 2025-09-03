/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer_main.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:24:59 by meid              #+#    #+#             */
/*   Updated: 2025/07/17 23:04:34 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

bool FileReplacer::replacerBotton()
{
	if (_toReplace.empty()) {
		if (!emptyreplace())
			return false;
	}
	if (_toFind.empty()) {
		if (!emptytofind())
			return false;
	}
	std::ifstream file(_fileName.c_str());  // C++98: pass C-style string //  O_NOFOLLOW
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

std::string    FileReplacer::change_line(std::string line, int *i, int start, int end)
{
	std::string result;
	result += line.substr(0, start);
	result += _toReplace;
	result += line.substr(end + 1);
	*i = start + _toReplace.length() - 1;
	return (result);
}