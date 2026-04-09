
#include "utils/PrintWithColor.hpp"
#include "utils/ErrorMessages.hpp"

void PrintWithColor::printRed(const std::string& str) {
    std::cout << RED << str << RESET << std::endl;
}

void PrintWithColor::printGreen(const std::string& str) {
    std::cout << GREEN << str << RESET << std::endl;
}

void PrintWithColor::printYellow(const std::string& str) {
    std::cout << YELLOW << str << RESET << std::endl;
}

void PrintWithColor::printBlue(const std::string& str) {
    std::cout << BLUE << str << RESET << std::endl;
}

void PrintWithColor::printMagenta(const std::string& str) {
    std::cout << MAGENTA << str << RESET << std::endl;
}

void PrintWithColor::printBrightMagenta(const std::string& str) {
    std::cout << BRIGHT_MAGENTA << str << RESET << std::endl;
}

void PrintWithColor::printBrightYellow(const std::string& str) {
    std::cout << BRIGHT_YELLOW << str << RESET << std::endl;
}

void PrintWithColor::printMap(const std::map<std::string, double>& m) {
    for (std::map<std::string, double>::const_iterator it = m.begin(); it != m.end(); ++it) {
        // print date in cyan, value in green
        std::cout << CYAN << it->first << RESET << " => "
                  << GREEN << it->second << RESET << std::endl;
    }
}

void PrintWithColor::printResultLine(const std::string& date, double bitcoinValue, double inputValue) {
    if (inputValue < 0) {
        std::cout << RED << ErrorMessages::NOT_POSITIVE_NUMBER << RESET << std::endl;
        return;
    }
    unsigned long long result = static_cast<unsigned long long>(bitcoinValue * inputValue);
    if (result > INT_MAX || inputValue > 1000) {
        std::cout << RED << ErrorMessages::TOO_LARGE_NUMBER << RESET << std::endl;
        return;
    }
    std::cout << CYAN << date << RESET
              << " => "
              << YELLOW << inputValue << RESET
              << " = "
              << GREEN << (bitcoinValue * inputValue) << RESET
              << std::endl;
}