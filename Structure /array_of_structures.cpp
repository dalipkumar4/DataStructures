#include <iostream>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
    Student students[3] = {
        {1, "Dalip", 89.5},
        {2, "Kashish", 92.0},
        {3, "Rohit", 78.0}
    };

    for(int i = 0; i < 3; i++) {
        cout << students[i].name << " got " << students[i].marks << " marks." << endl;
    }

    return 0;
}
