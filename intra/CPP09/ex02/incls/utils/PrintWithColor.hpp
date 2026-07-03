#ifndef PRINTWITHCOLOR_HPP
#define PRINTWITHCOLOR_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define MAGENTA "\033[35m"
#define CYAN  "\033[96m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_YELLOW "\033[93m"

/*
    PrintWithColor namespace
    This namespace is used to print the output with color
    it can be:
    - print the string with color
    - create castomize funtions to pret some data types with color
    - or to print castomize output with color like the standard output from
        the subject that was implemented in printStandardOutput function
*/

namespace PrintWithColor {
    void printRed(const std::string& str);
    void printRedError(const std::string& str);
    void printGreen(const std::string& str);
    void printYellow(const std::string& str);
    void printBlue(const std::string& str);
    void printMagenta(const std::string& str);
    void printBrightMagenta(const std::string& str);
    void printBrightYellow(const std::string& str);
    void printVector(const std::vector<int>& vec);
    void printDeque(const std::deque<int>& deq);
    void printstanderdOutput(const std::vector<int>& beforeVec,
                                        const std::vector<int>& afterVec,
                                        double vecTime, double dequeTime);

};

#endif