/*
https://www.codechef.com/learn/course/college-oops-cpp/CPOPCPP01/problems/OPCPP10

This program defines a simple class Student, creates an instance of the class, and checks if a student is eligible based on specific conditions.

The class contains:

Data Members:
name (string) — Stores the student's name.
score (int) — Stores the student's score.
age (int) — Stores the student's age.

eligible() — A method that checks eligibility based on:
score > 10
age > 20
If both conditions are satisfied, it outputs "YES". Otherwise, it outputs "NO".

Creates an object obj of class Student.
Sets the following data for the object:
name = "Tom"
score = 15
age = 21
Calls the eligible() method to evaluate and display eligibility.
*/
#include <iostream>
using namespace std;

class Student {
  public:
    string name;
    int score;
    int age;

    void eligible(){
        if(score>10 && age>20){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
};


int main() {
    Student obj;
    obj.name = "Tom";
    obj.score = 15;
    obj.age  = 21;
    obj.eligible();

    return 0;
}
