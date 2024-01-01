//
//  Lab04-1.cpp
//  Lab04-1
//
//  Modified by Jeman Park on 2023/10/17.
//

#include <iostream>
#include "StackType.h"
using namespace std;

int main() {
    
    StackType stack;
    
    stack.Pop();
    // [ERROR] Stack is empty. POP failed.
    
    stack.Push(0);
    stack.Push(1);
    stack.Push(2);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);
    stack.printStack();
    //  (top) 5    4    3    2    2    1    0    ]
    
    cout << "[POP]: " << stack.Pop() << endl;
    // [POP]: 5
    cout << "[POP]: " << stack.Pop() << endl;
    // [POP]: 4
    
    stack.printStack();
    //  (top) 3    2    2    1    0    ]
    
    stack.ReplaceItem(2, 1);
    stack.printStack();
    //  (top) 3    1    1    1    0    ]
    
    stack.ReplaceItem(1, 4);
    stack.printStack();
    //   (top) 3    4    4    4    0    ]
    
    
    return 0;
    // STACK is completely deleted.
    
}

