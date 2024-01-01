//
//  Lab03-1.cpp
//  Lab03
//
//  Modifieid by Jeman Park on 2023/10/03.
//

#include <iostream>
#include <cstdlib>
#include "QueType.h"
using namespace std;


int main() {
    
    QueType queue(5);
    queue.printQueue();
    
    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);
    queue.printQueue();
    // [ 1    2    3    4    5 ]
    
    queue.Enqueue(10);
    // [ERROR] Queue is full. Enqueue failed.
    queue.printQueue();
    // [ 1    2    3    4    5 ]
    
    ItemType item;
    item = queue.Dequeue();
    cout << "Dequeued item: " << item << endl;
    //Dequeued item: 1
    item = queue.Dequeue();
    cout << "Dequeued item: " << item << endl;
    // Dequeued item: 2
    item = queue.Dequeue();
    cout << "Dequeued item: " << item << endl;
    // Dequeued item: 3
    item = queue.Dequeue();
    cout << "Dequeued item: " << item << endl;
    // Dequeued item: 4
    
    queue.printQueue();
    //[ 5 ]
    
    queue.Enqueue(6);
    queue.Enqueue(7);
    queue.Enqueue(8);
    queue.printQueue();
    // [ 5    6    7    8 ]
    
    item = queue.Dequeue();
    item = queue.Dequeue();
    item = queue.Dequeue();
    item = queue.Dequeue();
    item = queue.Dequeue();
    // [ERROR] Queue is empty. Dequeue failed.
    
    return 0;
}

