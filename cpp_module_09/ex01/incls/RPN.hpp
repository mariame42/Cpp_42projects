#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>

#include "utils/PrintWithColor.hpp"
#include "utils/ErrorMessages.hpp"
#include <string>
#include <cctype>

class RPN
{
    private :
        std::stack<int> _rpnStack;
        int _result;

    public :
        RPN();
        RPN(const RPN& src);
        RPN& operator=(const RPN& src);
        ~RPN();

        void evaluate(const std::string& expr);
        int getResult() const;
};

#endif
