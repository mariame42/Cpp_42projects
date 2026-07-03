#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <climits>

// ------------------- OCCF -------------------

RPN::RPN() : _result(0) {}

RPN::RPN(const RPN& src)
{
    *this = src;
}

RPN& RPN::operator=(const RPN& src)
{
    if (this != &src)
    {
        _result = src._result;
        _rpnStack = src._rpnStack;
    }
    return *this;
}

RPN::~RPN() {}

// ------------------- GET RESULT -------------------

int RPN::getResult() const
{
    return _result;
}

// ------------------- STRICT STRING TO INT -------------------

static int strToInt(const std::string& str)
{
    if (str.empty())
        throw std::logic_error(ErrorMessages::EMPTY_STRING_ERROR);

    std::size_t i = 0;
    bool neg = false;
    if (str[0] == '-' || str[0] == '+')
    {
        if (str.size() == 1)
            throw std::logic_error(ErrorMessages::INVALID_INPUT_ERROR + str);
        neg = (str[0] == '-');
        ++i;
    }
    if (i >= str.size())
        throw std::logic_error(ErrorMessages::INVALID_INPUT_ERROR + str);

    long long mag = 0;
    const long long limit = neg ? (static_cast<long long>(INT_MAX) + 1) : INT_MAX;

    for (; i < str.size(); ++i)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            throw std::logic_error(ErrorMessages::INVALID_INPUT_ERROR + str);
        mag = mag * 10 + (str[i] - '0');
        if (mag > limit)
            throw std::logic_error(ErrorMessages::NUMBER_TOO_LARGE_ERROR);
    }
    return neg ? static_cast<int>(-mag) : static_cast<int>(mag);
}

namespace {

int applyBinaryOp(int lhs, char op, int rhs)
{
    const long long a = static_cast<long long>(lhs);
    const long long b = static_cast<long long>(rhs);
    long long r = 0;

    switch (op)
    {
        case '+':
            r = a + b;
            break;
        case '-':
            r = a - b;
            break;
        case '*':
            r = a * b;
            break;
        case '/':
            if (rhs == 0)
                throw std::logic_error(ErrorMessages::DIVISION_BY_ZERO_ERROR);
            r = a / b;
            break;
        default:
            throw std::logic_error(ErrorMessages::INVALID_OPERATOR_ERROR);
    }

    if (r < INT_MIN || r > INT_MAX)
        throw std::logic_error(ErrorMessages::NUMBER_TOO_LARGE_ERROR);
    return static_cast<int>(r);
}

}

// ------------------- EVALUATE -------------------

void RPN::evaluate(const std::string& expr)
{
    while (!_rpnStack.empty())
        _rpnStack.pop();

    std::stringstream input(expr);
    std::string token;

    while (input >> token)
    {
        // NUMBER
        bool isNumber = !token.empty();
        for (size_t i = 0; i < token.size(); i++)
        {
            if (i == 0 && (token[i] == '-' || token[i] == '+'))
            {
                if (token.size() == 1)
                    isNumber = false;
                continue;
            }
            if (!std::isdigit(static_cast<unsigned char>(token[i])))
            {
                isNumber = false;
                break;
            }
        }

        if (isNumber)
        {
            int value = strToInt(token);
            if (!EVALATE_ARG_BUGGER_THAN_10 && value > 10)
                throw std::logic_error(ErrorMessages::NUMBER_TOO_LARGE_ERROR);
        
            _rpnStack.push(value);
        }
        // OPERATOR
        else if (token.size() == 1 &&
                (token[0] == '+' || token[0] == '-' ||
                 token[0] == '*' || token[0] == '/'))
        {
            if (_rpnStack.size() < 2)
                throw std::logic_error(ErrorMessages::NOT_ENOUGH_NUMBERS_ERROR);
        

            int rhs = _rpnStack.top(); _rpnStack.pop();
            int lhs = _rpnStack.top(); _rpnStack.pop();

            const int res = applyBinaryOp(lhs, token[0], rhs);

            _rpnStack.push(res);
        }
        else
        {
            throw std::logic_error(ErrorMessages::INVALID_TOKEN_ERROR);
        }
    }

    // MUST end with exactly one result
    if (_rpnStack.size() != 1)
        throw std::logic_error(ErrorMessages::EXTRA_NUMBERS_ERROR);


    _result = _rpnStack.top();
}