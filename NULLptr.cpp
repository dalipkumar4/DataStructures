#include<iostream>
using namespace std;

class Patient {
    public:
        string name;
        int age;

        // Constructor
        Patient(string n,int a){
            name = n;
            age = a;
            cout << "New patient admitted: " << name << ", Age: " << age << endl;
        }

        void checkup(){
            cout << "Checking patient" << name << "..." << endl;
        }

        // Destructor
        ~Patient(){
            cout << "Patient " << name << "has been discharged." << endl;
        }
};

int main(){
    // Pointer to patient object
    Patient* p1 = nullptr; // currently no patient (null pointer)

    if(p1 == nullptr){
        cout << "No patient allocated yet." << endl;
    }

    // New patient arrives (dynamic allocation using 'new')
    p1 = new Patient("Krish",34);

    // Doctor performs checkup
    p1->checkup();

    // Discharge the patient (deallocate memory)
    delete p1;
    p1 = nullptr;

    if(p1 == nullptr){
        cout << "Bed is now empty and ready for next patient." << endl;
    }

    return 0;
}
