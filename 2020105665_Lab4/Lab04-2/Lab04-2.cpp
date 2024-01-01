//
//  Lab04-2.cpp
//  Lab04-2
//
//  Modified by Jeman Park on 2023/10/17.
//

#include <iostream>
#include "QueType.h"
using namespace std;

int main() {

    QueType<int> queue;
    int temp_item;
    queue.Dequeue(temp_item);
    // [ERROR] Queue is empty. Dequeue failed.

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(3);
    queue.Enqueue(2);
    queue.Enqueue(4);
    queue.printQueue();
    // (front) [    1    2    3    3    2    4    ] (rear)

    queue.ReplaceItem(2, 6);
    queue.printQueue();
    // (front) [    1    6    3    3    6    4    ] (rear)


    queue.Dequeue(temp_item);
    cout << "[DEQUEUE]: " << temp_item << endl;
    // [DEQUEUE]: 1
    queue.Dequeue(temp_item);
    cout << "[DEQUEUE]: " << temp_item << endl;
    // [DEQUEUE]: 6
    queue.Dequeue(temp_item);
    cout << "[DEQUEUE]: " << temp_item << endl;
    // [DEQUEUE]: 3

    queue.ReplaceItem(6, 2);
    queue.printQueue();
    // (front) [    3    2    4    ] (rear)


    return 0;
}

