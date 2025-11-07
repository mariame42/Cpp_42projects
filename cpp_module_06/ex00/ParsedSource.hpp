#ifndef PARSEDSOURCE_HPP
# define PARSEDSOURCE_HPP

#include <string>

// Use enum for internal logic (type-safe, fast comparisons)
// String defines only if you need them for output/display
enum InputType{
    Char,
    Int,
    Float,
    Double,
    PseudoLiterals,
    Null
};

// Helper: convert enum to string for display/debugging (optional)
inline std::string inputTypeToString(InputType type)
{
    switch (type) {
        case Char:              return "char";
        case Int:               return "int";
        case Float:             return "float";
        case Double:            return "double";
        case PseudoLiterals:    return "pseudo literals";
        case Null:              return "null";
        default:                return "unknown";
    }
}

class ParsedSource {
    private:
        bool isNaN;
        bool isInf;
        int  sign;
        bool hasChar;
        char charValue;
        bool hasInt;
        long long intValue;
        bool hasFloat;
        float floatValue;
        bool hasDouble;
        double doubleValue;
    public:
        ParsedSource(const std::string& input, InputType type);
        ~ParsedSource();
        bool getisNaN() const;
        bool getisInf() const;
        int getsign() const;
        bool gethasChar() const;
        char getcharValue() const;
        bool gethasInt() const;
        long long getintValue() const;
        bool gethasFloat() const;
        float getfloatValue() const;
        bool gethasDouble() const;
        double getdoubleValue() const;
};

// ParsedSource parse_source(const std::string& input, InputType type);

#endif