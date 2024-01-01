//
//  Lab02-2.cpp
//  Lab02-3
//
//  Modified by Jeman Park on 2023/09/25.

#include <iostream>
#include "double_stack.h"
using namespace std;



int main(int argc, const char * argv[]) {

    DoubleStack<int> DS;
    /* Feel free to edit codes below (test with more cases) */
    
    DS.Push(1050);
    DS.Push(3);
    DS.Push(10);
    DS.Push(200);
    DS.Push(2000);
    DS.Push(50);
    DS.Push(1200);
    
    DS.Print();
    // [ 3    10    200    50     | 1200    2000    1050     ]
    
    cout << DS.Pop(TOP_BIG) << endl;
    // 1200
    cout << DS.Pop(TOP_SMALL) << endl;
    // 50
    
    cout << DS.Pop(TOP_BIG) << endl;
    // 2000
    cout << DS.Pop(TOP_BIG) << endl;
    // 1050
    cout << DS.Pop(TOP_BIG) << endl;
    // -1 (ERROR)
    
    cout << DS.Pop(TOP_SMALL) << endl;
    // 200
    cout << DS.Pop(TOP_SMALL) << endl;
    // 10
    cout << DS.Pop(TOP_SMALL) << endl;
    // 3
    cout << DS.Pop(TOP_SMALL) << endl;
    // -1 (ERROR)
    
    DS.Print();
    // [  |  ]
    
    return 0;
}
