#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number; // cin is a predefined object in the iostream library used to accept standard input from the keyboard, typically using the extraction operator (>>). 
    cout << "You entered: " << number << endl;

    // type casting in c++

    // Implicit Type Casting
    int x=10;
    double y = x;
    cout<<y<<endl;

    int a = 5;
    double b = 2;
    cout << a / b << endl;

    // Explicit Type Casting - You tell C++ to convert manually.

    int p = 5;
    int q = 2;
    cout << (double) p / q << endl; // (double) converts p int into p double.

    // another example
    int one = 10; //4 bytes
    char two = 'd'; // 1 byte
    two=one;
    cout<<two; // won't give any readable output 

    // another example
    int on = 10; //4 bytes
    char tw = 'd'; // 1 byte
    on=tw;
    cout<<on; // ASCII code for the lowercase letter d is 100 (decimal)

    // if-else in c++
    int number = 10;
    if (number > 15) {
        cout << "Number is greater than 15";
    } else if (number > 5) {
        cout << "Number is greater than 5 but less than or equal to 15";
    } else {
        cout << "Number is 5 or less";
    }   

    return 0;
}   