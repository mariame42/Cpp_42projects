

// static std::string to_char(std::string input, InputType type, ParsedSource parsed)
// {
//     (void)input;
//     (void)type;
    
//     // Check for NaN/Inf first - these are impossible to convert to char
//     if (parsed.getisNaN() || parsed.getisInf())
//         return ("char: impossible");
    
//     // Get the numeric value from already-parsed source
//     double value = 0.0;
//     if (parsed.gethasChar())
//         value = static_cast<double>(parsed.getcharValue());
//     else if (parsed.gethasInt())
//         value = static_cast<double>(parsed.getintValue());
//     else if (parsed.gethasFloat())
//         value = static_cast<double>(parsed.getfloatValue());
//     else if (parsed.gethasDouble())
//         value = parsed.getdoubleValue();
//     else
//         return ("char: impossible");

//     // Check if value is out of char range (impossible cases)
//     if (value < 0 || value > 255)
//         return ("char: impossible");
    
//     // Check if value is a whole number (for float/double inputs)
//     if (parsed.gethasFloat() || parsed.gethasDouble())
//     {
//         if (value != static_cast<long long>(value))
//             return ("char: impossible");
//     }
    
//     // Convert to char (0-255 range)
//     int charCode = static_cast<int>(value);
    
//     // Check if printable (32-126) or non-displayable (0-31, 127)
//     if (charCode < 32 || charCode == 127)
//         return ("char: Non displayable");
    
//     char c = static_cast<char>(charCode);
//     return ("char: '" + std::string(1, c) + "'");
// }



