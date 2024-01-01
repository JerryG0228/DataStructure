//
//  Lab01-2.cpp
//  Lab01
//
//  Created by Jeman Park on 2023/09/18.
//

#include <iostream>
using namespace std;

typedef char String[9];

// Definition of Student Record
struct StudentRecord
{
    String firstName;
    String lastName;
    int id;
    float gpa;
    int currentHours;
    int totalHours;
};

int main(int argc, const char * argv[]) {
    StudentRecord student;
    StudentRecord students[100];
    
    // Size of memories allocation for student
    cout << "sizeof(student): "<< sizeof(student) << endl;
    // Size of memories allocation for students
    cout << "sizeof(students): "<< sizeof(students) << endl;
    
    return 0;
}
