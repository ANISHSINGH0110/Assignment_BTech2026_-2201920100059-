/*
Create a C++ program that reads an integer from the user and handles the case when the entered integer is outside a specified valid range. Implement the following components:

Declare two integer constants, MIN_VALUE and MAX_VALUE, representing the inclusive lower and upper bounds of the valid range. Set MIN_VALUE to -1000 and MAX_VALUE to 1000.
try block:
If the entered integer is less than MIN_VALUE or greater than MAX_VALUE, throw an exception of type std::out_of_range with an appropriate error message.
catch block:
Catch the std::out_of_range exception.
Display an error message indicating that the entered integer is out of the specified range.

Given the integer value as 2000. Complete the code to handle the exception.
*/
#include <iostream>
#include <stdexcept>
using namespace std;

const int MIN_VALUE = -1000;
const int MAX_VALUE = 1000;

int main() {
    try {
        int value = 2000;

        if (value < MIN_VALUE || value > MAX_VALUE) {
            throw out_of_range("Entered integer is out of the specified range.");
        }

        cout << "You entered: " << value << endl;
    }
    catch (const out_of_range& ex) {
        cout << "Error: " << ex.what() << endl;
    }

    return 0;
}
