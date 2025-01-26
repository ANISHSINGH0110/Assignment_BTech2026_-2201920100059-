// Platform used programiz
https://app.programiz.pro/course/practice-cpp-oop/area-of-rectangle?page=1

//Problem Description
//Create a program to find the area of a rectangle.

#include<iostream>
using namespace std;

class Rectangle {
    public:

        int length;
        int breadth;
    
        // function to compute the area of rectangle
        void calculate_area() {

            // calculate the area
            int area = length*breadth;
            cout << area << endl;
        }
};

int main() {
    
    // create an object of Rectangle
     Rectangle r;
     int l,b;
        
    // get input for length and breadth of the object
    cin >> l >> b;
    
    // call the calculate_area() function using the object
     r.length = l;
     r.breadth = b;
     r.calculate_area();
        
    return 0;
}