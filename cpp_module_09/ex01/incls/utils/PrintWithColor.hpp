#ifndef PRINTWITHCOLOR_HPP
#define PRINTWITHCOLOR_HPP

#include <string>
#include <iostream>
#include <map>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
#define MAGENTA "\033[35m"
#define CYAN  "\033[96m"
#define BRIGHT_MAGENTA "\033[95m"
#define BRIGHT_YELLOW "\033[93m"

#define INT_MAX 2147483647

class PrintWithColor {
private:
    PrintWithColor() {}
    ~PrintWithColor() {}
public:
    static void printRed(const std::string& str);
    static void printGreen(const std::string& str);
    static void printYellow(const std::string& str);
    static void printBlue(const std::string& str);
    static void printMagenta(const std::string& str);
    static void printBrightMagenta(const std::string& str);
    static void printBrightYellow(const std::string& str);
};

#endif
