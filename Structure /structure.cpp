#include<iostream>
#include<stdlib.h>
using namespace std;

// Defining a structure
typedef struct Student {
    int rollNo;
    string name;
    float marks;
}s;

int main(){
    // Creating structure variable
    s s1;
    s s2 = {3,"Krish",59}; // Initialize values while declaring 


    // Assigning values
    s1.rollNo = 1; // Dot used to accessing structure members
    s1.name = "Dalip";
    s1.marks = 89.5;

    // Displaying values
    cout << "Roll no: " << s2.rollNo << endl;
    cout << "Name: " << s2.name << endl;
    cout << "Marks: " << s2.marks << endl;
    

    return 0;
}
