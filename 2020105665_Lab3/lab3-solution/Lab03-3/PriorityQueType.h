//
//  PriorityQueType.h
//  Lab03
//
//  Created by parkjeman on 2023/10/03.
//

#ifndef PRIORITYQUETYPE_H
#define PRIORITYQUETYPE_H

#define HIGH 1
#define LOW 2

#include <iostream>

typedef int ItemType;

// Definition of QUETYPE
class PriorityQueType
{
public:
    PriorityQueType(int max);
    ~PriorityQueType();
    bool IsEmpty(int priority);
    bool IsFull(int priority);
    void Enqueue(ItemType newItem, int priority);
    ItemType Dequeue();
    
    void printQueue();
    
private:
    int high_front;
    int high_rear;
    int low_front;
    int low_rear;
    ItemType* high_items;
    ItemType* low_items;
    int maxQue;
    
};

#endif /* PriorityQueType_hpp */
