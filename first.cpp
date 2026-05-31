// first c++ code 

#include<iostream>
#include <string>
#include <typeinfo>
using namespace std;

int main(){
    cout<<2+3<<endl;
    cout<<"hello world, this is my first c++ code\n";

    // Primitive Data Types
    int age = 25;                  // Integer
    double pi = 3.14159;           // Double precision floating point
    char grade = 'A';              // Character
    bool isReady = true;           // Boolean
    string name = "John";          // String (requires <string> header)

    // Output
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "Pi: " << pi << endl;
    cout << "Grade: " << grade << endl;
    cout << "Ready: " << isReady << endl;

    // Type Deduction with auto
    auto price = 99.99;            // Compiler deduces double
    auto code = "C++";             // Compiler deduces const char*

    cout << "Price: " << price << endl;
    cout << "Code: " << code << endl;

    // Get type names (mangled format, varies by compiler)
    cout << "age type: " << typeid(age).name() << std::endl;      // e.g., "i" (int)
    cout << "pi type: " << typeid(pi).name() << std::endl;        // e.g., "d" (double)


};