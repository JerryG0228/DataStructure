//
//  Student.h
//  Lab10
//
//  Modified by Jeman Park on 2023/12/5.
//

#ifndef _STUDENT_H
#define _STUDENT_H

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Student
{
public :
	void InitValue(int _id, char* _name, float _gpa);
	void getValue(int& _id, char* _name, float& _gpa);
	char* getName();
    int getID();
    float getGPA();
	void operator = (Student stu);

    
private :
	int id;
	char name[30];
	float gpa;
};


void Print(Student stu[], int numval);
void Swap(Student& item1, Student& item2);



#endif
