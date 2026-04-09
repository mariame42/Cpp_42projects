
#include "utils/PrintWithColor.hpp"
#include "utils/ErrorMessages.hpp"
#include <sstream>

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

void PrintWithColor::printVector(const std::vector<int>& vec) {
    std::cout << BLUE << "Values: " << RESET;
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        std::cout << CYAN << vec[i] << RESET;
        if (i + 1 < vec.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

// Before: 3 5 9 7 4
// After: 3 4 5 7 9
// Time to process a range of 5 elements with std::[..] : 0.00031 us
// Time to process a range of 5 elements with std::[..] : 0.00014 us

void PrintWithColor::printstanderdOutput(const std::vector<int>& beforeVec,
                                        const std::vector<int>& afterVec,
                                        double vecTime, double dequeTime)
{
    std::cout << BLUE << "Before: " << RESET;
    for (std::size_t i = 0; i < beforeVec.size(); ++i)
    {
        std::cout << CYAN << beforeVec[i] << RESET;
        if (i + 1 < beforeVec.size())
            std::cout << " ";
    }
    std::cout << std::endl;

    std::cout << BLUE << "After:  " << RESET;
    for (std::size_t i = 0; i < afterVec.size(); ++i)
    {
        std::cout << GREEN << afterVec[i] << RESET;
        if (i + 1 < afterVec.size())
            std::cout << " ";
    }
    std::cout << std::endl;

    std::stringstream vecSs;
    vecSs << "Time to process a range of " << beforeVec.size()
          << " elements with std::vector : " << vecTime << " us";
    printBrightYellow(vecSs.str());

    std::stringstream deqSs;
    deqSs << "Time to process a range of " << beforeVec.size()
          << " elements with std::deque : " << dequeTime << " us";
    printBrightMagenta(deqSs.str());
}