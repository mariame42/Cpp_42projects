#ifndef PRINTWITHCOLOR_HPP
#define PRINTWITHCOLOR_HPP

#include <string>
#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define MAGENTA "\033[35m"
#define CYAN  "\033[96m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_YELLOW "\033[93m"

namespace PrintWithColor {
    void printRed(const std::string& str);
    void printRedError(const std::string& str);
    void printGreen(const std::string& str);
    void printYellow(const std::string& str);
    void printBlue(const std::string& str);
    void printMagenta(const std::string& str);
    void printBrightMagenta(const std::string& str);
    void printBrightYellow(const std::string& str);
}

#endif
