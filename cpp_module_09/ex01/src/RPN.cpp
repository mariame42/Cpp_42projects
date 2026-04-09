#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN()
{
    this->_result = 0;
}

static int strToInt(const std::string& str)
{
    std::stringstream ss(str);
    int res = 0;
    ss >> res;
    return (res);
}

void RPN::evaluate(const std::string& expr)
{
    while (!this->_rpnStack.empty())
        this->_rpnStack.pop();

    std::stringstream input(expr);
    std::string token;

    while (input >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
        {
            this->_rpnStack.push(strToInt(token));
        }
        else if (token.size() == 1
            && (token[0] == '+' || token[0] == '-' || token[0] == '/' || token[0] == '*'))
        {
            if (this->_rpnStack.size() < 2)
                throw std::logic_error(ErrorMessages::EXTRA_OPERATION);

            int rhs = this->_rpnStack.top();
            this->_rpnStack.pop();
            int lhs = this->_rpnStack.top();
            this->_rpnStack.pop();

            int res = 0;
            if (token[0] == '+')
                res = lhs + rhs;
            else if (token[0] == '-')
                res = lhs - rhs;
            else if (token[0] == '/')
            {
                if (rhs == 0)
                    throw std::logic_error(ErrorMessages::INVALED_INPUT);
                res = lhs / rhs;
            }
            else
                res = lhs * rhs;
            this->_rpnStack.push(res);
        }
        else
            throw std::logic_error(ErrorMessages::INVALED_INPUT);
    }

    if (this->_rpnStack.size() > 1)
        throw std::logic_error(ErrorMessages::EXTRA_NUMS);
    if (this->_rpnStack.empty())
        throw std::logic_error(ErrorMessages::INVALED_INPUT);
    this->_result = this->_rpnStack.top();
    this->_rpnStack.pop();
}

RPN::RPN(const RPN& src)
{
    (*this) = src;
}

RPN& RPN::operator=(const RPN& src)
{
    if (this != &src)
    {
        this->_result = src._result;
        this->_rpnStack = src._rpnStack;
    }
    return (*this);
}

RPN::~RPN()
{
}

int RPN::getResult() const
{
    return (this->_result);
}
