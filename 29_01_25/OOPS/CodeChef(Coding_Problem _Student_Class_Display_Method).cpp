/*
https://www.codechef.com/learn/course/college-oops-cpp/CPOPCPP01/problems/OPCPP03
Coding Problem - Student Class Display Method
You are given a class Student having attributes as name and age and a display method to print name and age of Student. Create a object of student class with given name and age. Use display method to print information of the Student.

Input Format
The first line of input will contain a string and integer representing name and age respectively.

Output Format
Use display method to print the name and age of Student.
*/



#include<iostream>
using namespace std;

class Student{
public:
    string name;
    int age;

    void display(){
        cout<<name<<" "<<age<<endl;
    }
};

int main(){
    Student s;
    cin>>s.name>>s.age;
    s.display();
    
    return 0;
}