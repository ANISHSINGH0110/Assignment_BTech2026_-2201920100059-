/*
https://www.codechef.com/learn/course/college-oops-cpp/CPOPCPP01/problems/OPCPP11
Write a class Rectangle with length and breadth as attribute and area and perimeter as methods. Given length and breadth as input, Print area and perimeter of rectangle using area and perimeter methods respectively.

Input Format
The first line of input contains length of rectangle.
The second line of input contains breadth of rectangle.
Output Format
First line contains the output of area method of Rectangle.
Second line contains the output of perimeter method of Rectangle.
*/

#include <iostream>
using namespace std;

class Rectangle{
public:
    int length;
    int breadth;
    
    void area(){
        cout<<length*breadth<<endl;
    }
    void perimeter(){
        cout<<2*(length+breadth)<<endl;
    }
};

int main() {
    Rectangle r;
    cin>>r.length>>r.breadth;
    r.area();
    r.perimeter();
	return 0;
}
