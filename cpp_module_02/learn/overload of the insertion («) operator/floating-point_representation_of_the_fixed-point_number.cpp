
#include <iostream>

class MyClass {
    int data;
public:
    MyClass(int d) : data(d) {}

    // Friend declaration to allow access to private data
    friend std::ostream& operator<<(std::ostream& os, const MyClass& obj);
};

// Overloaded insertion operator as a global function
std::ostream& operator<<(std::ostream& os,  const MyClass& obj) {
    // Access private member 'data' and stream it to 'os'
    os << "MyClass(" << obj.data << ")";
    return os; // Return the stream for chaining
}

int main() {
    MyClass obj(10);
    std::cout << "Output: " << obj << std::endl; // Output: Output: MyClass(10)
    return 0;
}