#ifndef RPN_HPP
# define RPN_HPP


#ifndef WITH_ERROR_DETAILS
# define WITH_ERROR_DETAILS 0
#endif

#ifndef EVALATE_ARG_BUGGER_THAN_10
# define EVALATE_ARG_BUGGER_THAN_10 0
#endif

#include <stack>
#include <iostream>
#include "utils/PrintWithColor.hpp"
#include "utils/ErrorMessages.hpp"
#include <string>
#include <cctype>

/*
    the container for this program is a stack
    why a stack ? because we need to be able to evaluate the expression in the correct order
    and that means we need to be able to pop the numbers and operators in the correct order
*/

/*
    RPN class
    This class is used to evaluate the inverted Polish mathematical expression (RPN)
        the consept is very simple :
            - we have a stack
            - we have a string of numbers and operators
            - we need to evaluate the expression in the correct order
            - when we encounter a number, we push it onto the stack
            - when we encounter an operator, we pop the two numbers from the stack and apply the operator
            - at the end if there is any number left in the stack, the expression is invalid
            - or if there is any operator left from the input string, the expression is invalid
*/
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
