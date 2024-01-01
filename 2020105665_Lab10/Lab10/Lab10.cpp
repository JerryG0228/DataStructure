//
//  Lab10.cpp
//  Lab10
//
//  Modified by Jeman Park on 2023/12/5.
//

#include <iostream>
#include "SelectionSort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"

using namespace std;

int main()
{
    Student stu[100];
    int num_student = 7;
    stu[0].InitValue(2023200121, (char*)"Brendan", 4.3);
    stu[1].InitValue(2023200045, (char*)"Ken", 3.2);
    stu[2].InitValue(2023200032, (char*)"Amit", 4.1);
    stu[3].InitValue(2023200065, (char*)"David", 3.6);
    stu[4].InitValue(2023200100, (char*)"Anna", 2.9);
    stu[5].InitValue(2023200078, (char*)"Runze", 3.3);
    stu[6].InitValue(2023200003, (char*)"Yiting", 2.7);

    // Exercise #10-1
    cout << "Selection Sort: Ascending order by name:" << endl;
    SelectionSort(stu, num_student);
    Print(stu, num_student);
    //    2005200131    Amit    4.1
    //    2005200131    Anna    2.9
    //    2003200111    Brendan    4.3
    //    2005200131    David    3.6
    //    2004200121    Ken    3.2
    //    2005200131    Runze    3.3
    //    2005200131    Yiting    2.7
    
    
    // Exercise #10-2
    cout << "Bubble Sort: Descending order by GPA:" << endl;
    BubbleSort(stu,num_student);
    Print(stu, num_student);
    //    2003200111    Brendan    4.3
    //    2005200131    Amit    4.1
    //    2005200131    David    3.6
    //    2005200131    Runze    3.3
    //    2004200121    Ken    3.2
    //    2005200131    Anna    2.9
    //    2005200131    Yiting    2.7
    
    
    // Exercise #10-3
    cout << "Insertion Sort: Ascending order by ID:" << endl;
    InsertionSort(stu,num_student);
    Print(stu, num_student);
    //    2023200003    Yiting    2.7
    //    2023200032    Amit    4.1
    //    2023200045    Ken    3.2
    //    2023200065    David    3.6
    //    2023200078    Runze    3.3
    //    2023200100    Anna    2.9
    //    2023200121    Brendan    4.3
    
    return 0;

}

