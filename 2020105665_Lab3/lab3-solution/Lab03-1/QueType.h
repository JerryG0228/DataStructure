//
//  QueType.h
//  Lab03-1
//
//  Modified by Jeman Park on 2023/10/03.
//

#ifndef QUETYPE_H
#define QUETYPE_H

#include <iostream>



typedef int ItemType;

// Definition of QUETYPE
class QueType
{
public:
    QueType(int max);
    ~QueType();
    void MakeEmpty();
    bool IsEmpty() const;
    bool IsFull() const;
    void Enqueue(ItemType newItem);
    ItemType Dequeue();
    
    void printQueue();
    
private:
    int front;
    int rear;
    ItemType* items;
    int maxQue;
    int length;
};


#endif /* binary_search_hpp */
