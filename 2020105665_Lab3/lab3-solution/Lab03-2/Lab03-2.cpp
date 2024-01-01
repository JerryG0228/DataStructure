//
//  Lab03-2.cpp
//  Lab03-2
//
//  Modified by Jeman Park on 2023/10/03.
//

#include <iostream>
#include <cstdlib>
#include "MinQueType.h"
using namespace std;

int main() {

    QueType queue(5);
    ItemType item;

    queue.Enqueue(1);
    queue.Enqueue(4);
    queue.Enqueue(5);
    queue.Enqueue(3);
    queue.printQueue();
    // [ 1    4    5    3 ]
    
    item = queue.MinDequeue();
    cout << "minItem : " << item << endl;
    // minItem : 1
    item = queue.MinDequeue();
    cout << "minItem : " << item << endl;
    // minItem : 3
    queue.printQueue();
    // [ -1    4    5    -1 ]

    queue.Enqueue(7);
    queue.printQueue();
    // [ 7    4    5    -1 ]
    
    
    item = queue.MinDequeue();
    cout << "minItem : " << item << endl;
    // minItem : 4
    item = queue.MinDequeue();
    cout << "minItem : " << item << endl;
    // minItem : 5
    item = queue.MinDequeue();
    cout << "minItem : " << item << endl;
    // minItem : 7
    queue.printQueue();
    // [ -1    -1    -1    -1 ]

    queue.Enqueue(10);
    queue.Enqueue(11);
    queue.Enqueue(12);
    queue.Enqueue(13);
    queue.Enqueue(14);
    queue.Enqueue(15);
    // [ERROR] Queue is full. Enqueue failed.
    queue.printQueue();
    // [ 10    11    12    13    14 ]

    item = queue.MinDequeue();
    item = queue.MinDequeue();
    item = queue.MinDequeue();
    item = queue.MinDequeue();
    item = queue.MinDequeue();
    queue.printQueue();
    // [ -1    -1    -1    -1    -1 ]

    item = queue.MinDequeue();
    // [ERROR] Queue is empty (all values == -1). Dequeue failed.

    return 0;
}

