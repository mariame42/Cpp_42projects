#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

// Function to remove timestamp from a line
std::string removeTimestamp(const std::string& line) {
    size_t bracketStart = line.find('[');
    if (bracketStart != std::string::npos) {
        size_t bracketEnd = line.find(']', bracketStart);
        if (bracketEnd != std::string::npos) {
            return line.substr(bracketEnd + 1); // Return everything after the timestamp
        }
    }
    return line; // Return original line if no timestamp found
}

// Function to compare two files ignoring timestamps
bool compareFilesIgnoringTimestamps(const std::string& file1, const std::string& file2) {
    std::ifstream f1(file1.c_str());
    std::ifstream f2(file2.c_str());
    
    if (!f1.is_open()) {
        std::cout << "Error: Cannot open file " << file1 << std::endl;
        return false;
    }
    
    if (!f2.is_open()) {
        std::cout << "Error: Cannot open file " << file2 << std::endl;
        return false;
    }
    
    std::string line1, line2;
    int lineNumber = 1;
    bool filesMatch = true;
    
    while (std::getline(f1, line1) && std::getline(f2, line2)) {
        std::string cleanLine1 = removeTimestamp(line1);
        std::string cleanLine2 = removeTimestamp(line2);
        
        if (cleanLine1 != cleanLine2) {
            std::cout << "Mismatch at line " << lineNumber << ":" << std::endl;
            std::cout << "Expected: " << cleanLine2 << std::endl;
            std::cout << "Got:      " << cleanLine1 << std::endl;
            std::cout << "---" << std::endl;
            filesMatch = false;
        }
        lineNumber++;
    }
    
    // Check if one file is longer than the other
    if (std::getline(f1, line1)) {
        std::cout << "File " << file1 << " has more lines than " << file2 << std::endl;
        filesMatch = false;
    }
    
    if (std::getline(f2, line2)) {
        std::cout << "File " << file2 << " has more lines than " << file1 << std::endl;
        filesMatch = false;
    }
    
    f1.close();
    f2.close();
    
    return filesMatch;
}

int main() {
    std::cout << "=== Account Output Comparison Test ===" << std::endl;
    
    // First, run the account program and capture its output
    std::cout << "Running account program..." << std::endl;
    system("./account > my_output.log 2>&1");
    
    // Compare the output with the expected log
    std::cout << "Comparing output with expected log..." << std::endl;
    
    bool match = compareFilesIgnoringTimestamps("my_output.log", "19920104_091532.log");
    
    if (match) {
        std::cout << "✅ SUCCESS: Output matches expected log (ignoring timestamps)!" << std::endl;
    } else {
        std::cout << "❌ FAILURE: Output does not match expected log!" << std::endl;
    }
    
    std::cout << "\n=== Test Complete ===" << std::endl;
    
    return match ? 0 : 1;
} 