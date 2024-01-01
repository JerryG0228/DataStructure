//
//  Lab02-2.cpp
//  Lab02-2
//
//  Modified by Jeman Park on 2023/09/25.
//

#include <iostream>
#include "StackType.h"
using namespace std;

int main() {
    
    StackType stack;
    /* Feel free to edit codes below (test with more cases) */
    
    stack.Push(8);
    stack.Push(3);
    stack.Push(9);
    stack.Push(8);
    stack.Push(3);
    stack.Push(7);
    stack.Push(5);
    stack.Push(3);
    
    stack.printStack();
    // [ 8    3    9    8    3    7    5     (top)
    
    stack.ReplaceItem(3, 5);
    stack.printStack();
    // [ 8    5    9    8    5    7    5     (top)
    // All "3" are replaced by "5"
    
    return 0;
}
