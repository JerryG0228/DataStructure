//
//  Lab03-3.cpp
//  Lab03
//
//  Modified by Jeman Park on 2023/10/03.
//

#include <iostream>
#include <cstdlib>
#include "PriorityQueType.h"
using namespace std;


int main() {
    
    PriorityQueType prior_queue(5);
    
    prior_queue.Enqueue(1, HIGH);
    prior_queue.Enqueue(2, LOW);
    prior_queue.Enqueue(3, HIGH);
    prior_queue.Enqueue(4, LOW);
    prior_queue.Enqueue(5, LOW);
    prior_queue.Enqueue(6, LOW);
    prior_queue.Enqueue(7, LOW);
    prior_queue.Enqueue(8, LOW);
    // [ERROR] LOW Queue is full. Enqueue failed.
    
    prior_queue.printQueue();
    // HIGH: [ 1    3 ]
    // LOW: [ 2    4    5    6    7 ]
    
    ItemType item;
    item = prior_queue.Dequeue();
    cout << "Dequeued item: " << item << endl;
    // Dequeued item: 1
    item = prior_queue.Dequeue();
    cout << "Dequeued item: " << item << endl;
    // Dequeued item: 3
    prior_queue.printQueue();
    // HIGH: [ ]
    // LOW: [ 2    4    5    6    7 ]
    
    item = prior_queue.Dequeue();
    item = prior_queue.Dequeue();
    item = prior_queue.Dequeue();
    item = prior_queue.Dequeue();
    item = prior_queue.Dequeue();
    item = prior_queue.Dequeue();
    // [ERROR] Queue is empty. Dequeue failed.
    prior_queue.printQueue();
    // HIGH: [ ]
    // LOW: [ ]
    
    return 0;
}

