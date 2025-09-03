/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:21:07 by meid              #+#    #+#             */
/*   Updated: 2025/07/16 22:28:24 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

#include <iostream>
#include <fstream>
#include "FileReplacer.hpp"
#include <filesystem>
#include <iostream>
#include <fstream>


#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

class FileReplacer
{
    private:
        std::string _fileName;
        std::string _toFind;
        std::string _toReplace;
        std::string _outFile;
    public:
        FileReplacer(std::string fileName, std::string toFind, std::string  toReplace);
        ~FileReplacer();
        bool replacerBotton();
        bool openFiles(std::ifstream& in, std::ofstream& out);
        std::string check_line_and_change(std::string *linee);
        std::string    change_line(std::string line, int *i, int start, int end);
        bool  emptyreplace();
        bool isTooLarge(const std::string& filename);
        bool  emptytofind();
};


#endif