/*
This C++ program calculates the square root of an integer while handling potential errors when the input is negative.
If the input num is less than 0, an invalid_argument exception is thrown with an appropriate error message.
If the input is valid, the square root is computed using sqrt().
*/
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

// Function to calculate the square root of an integer
double calculateSquareRoot(int num) {
    if (num < 0) {
        throw invalid_argument("Invalid argument. Input must be a non-negative integer.");
    }
    return sqrt(num);
}


int main() {
    int input = -2;

    try {
        double squareRoot = calculateSquareRoot(input);
        cout << squareRoot << endl;
    }
    catch (const invalid_argument& ex) {
        cout << ex.what() << endl;
    }

    return 0;
}
