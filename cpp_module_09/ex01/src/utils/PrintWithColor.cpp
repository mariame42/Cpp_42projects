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
