/*

Encapsulation and Accessors Usage
We know that members declared as private are only accessible from within the class itself. They are not accessible from outside the class, including derived classes (in the case of inheritance).
Thus here we will learn how to access and modify the private data of classes.
We are given a class User having name and password as private data. This class also contain two methods get and set which are used to access and modify private data.

Note - "this" is used within a class member function to refer to the object on which the member function is called. You can refer to the code to know how to use it.

Task
Initially the name of the user is "Alice" and password is "Wonderland". Print this information using get function.
Now, change the name of the user to "Tom" and password to "Jerry" using set function. Print this information using get function.
Run this code to verify the output.


*/


#include <iostream>
using namespace std;

class User{
private:
    string name="Alice";
    string password="Wonderland";

public:
    void set(string name,string password){
        this->name = name;
        this->password = password;
    }
    void get(){
        cout<<name<<" "<<password<<endl;
    }
};

int main() {
    User obj;
    obj.get();
    obj.set("Tom","Jerry");
    obj.get();
    return 0;
}