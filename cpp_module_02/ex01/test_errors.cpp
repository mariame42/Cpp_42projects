#include "Fixed.hpp"
#include <iostream>

int main() {
    std::cout << "=== ERROR HANDLING TEST ===" << std::endl;
    
    // Test 1: Large integer (should throw)
    std::cout << "\n--- Testing Large Integer ---" << std::endl;
    try {
        Fixed large_int(1000000000);
        std::cout << "Large integer: " << large_int << std::endl;
    } catch (const std::out_of_range& e) {
        std::cout << "✅ Caught: " << e.what() << std::endl;
    }
    
    // Test 2: Large float (should throw)
    std::cout << "\n--- Testing Large Float ---" << std::endl;
    try {
        Fixed large_float(1000000000.0f);
        std::cout << "Large float: " << large_float << std::endl;
    } catch (const std::overflow_error& e) {
        std::cout << "✅ Caught: " << e.what() << std::endl;
    }
    
    // Test 3: Infinity (should throw)
    std::cout << "\n--- Testing Infinity ---" << std::endl;
    try {
        Fixed inf(1.0f / 0.0f);
        std::cout << "Infinity: " << inf << std::endl;
    } catch (const std::overflow_error& e) {
        std::cout << "✅ Caught: " << e.what() << std::endl;
    }
    
    // Test 4: NaN (should throw)
    std::cout << "\n--- Testing NaN ---" << std::endl;
    try {
        Fixed nan(0.0f / 0.0f);
        std::cout << "NaN: " << nan << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << "✅ Caught: " << e.what() << std::endl;
    }
    
    // Test 5: Normal values (should work)
    std::cout << "\n--- Testing Normal Values ---" << std::endl;
    Fixed normal1(42);
    Fixed normal2(3.14f);
    std::cout << "✅ Normal int: " << normal1 << std::endl;
    std::cout << "✅ Normal float: " << normal2 << std::endl;
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}