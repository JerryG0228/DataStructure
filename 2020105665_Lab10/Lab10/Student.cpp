//
//  Student.cpp
//  Lab10
//
//  Modified by Jeman Park on 2023/12/5.
//

#include "Student.h"

using namespace std;

void Swap(Student& item1, Student& item2) {

	Student tempStudent = item1;

	item1 = item2;
	item2 = tempStudent;
}


void Student::InitValue(int _id, char* _name, float _gpa)
{
	id = _id;
	strncpy(name, _name, sizeof(name));
	gpa = _gpa;
}

void Student::getValue(int& _id, char* _name, float& _gpa)
{
	_id = id;
    strncpy(_name, name, sizeof(name));
	_gpa = gpa;
}

char* Student::getName()
{
	return name;
}

int Student::getID()
{
    return id;
}

float Student::getGPA()
{
    return gpa;
}

void Student::operator = (Student stu)
{
	id = stu.id;
    strncpy(name,stu.name,sizeof(name));
	gpa = stu.gpa;
}


void Print(Student stu[], int numelement)
{
    int id;
    char name[30];
    float gpa;
    
    for(int i=0; i < numelement; i++)
    {
        stu[i].getValue(id, name, gpa);
        cout << id << "\t" << name << "\t" << gpa << endl;
    }
}
