//
//  QueType.cpp
//  Lab03-1
//
//  Modified by Jeman Park on 2023/10/03.
//

#include<iostream>
#include "QueType.h"


QueType::QueType(int max)
{
    /* Update the function here to use length */
    // maxQue must be initialized with "max" instead of "max + 1"

    // maxQue = max +1;
    maxQue = max;
    front = maxQue -1;
    rear = maxQue -1;
    
    items = new ItemType[maxQue];
    length = 0;
}

QueType::~QueType()
{
    delete [] items;
}

void QueType::MakeEmpty()
{
    front = maxQue;
    rear = maxQue;
}

bool QueType::IsEmpty() const
{
    /* Update the function here using "length" */
//    return (front == rear);
    return (length == 0);
}

bool QueType::IsFull() const
{
    /* Update the function here using "length" */
//    return ((rear + 1) % maxQue == front);
    return (length == maxQue);
}

void QueType::Enqueue(ItemType newItem)
{
    /* Update the function here to use length */
    if (IsFull()){
        std::cout << "[ERROR] Queue is full. Enqueue failed." << std::endl;
        return;
    }
    
    rear = (rear+1) % maxQue;
    items[rear] = newItem;
    length++;
}

ItemType QueType::Dequeue()
{
    /* Update the function here to use length */
    if (IsEmpty()){
        std::cout << "[ERROR] Queue is empty. Dequeue failed." << std::endl;
        return -1;
    }
    
    ItemType item;
    front = (front + 1) % maxQue;
    item = items[front];
    length--;
    return item;
}

void QueType::printQueue()
{
    
    std::cout << "front: " << front << std::endl;
    std::cout << "rear: " << rear << std::endl;
    if (IsEmpty()){
        std::cout << "[]" << std::endl;
        return;
    }
    int temp = (front + 1) % maxQue;
    
    std::cout << "[ ";
    
    while (temp != rear){
        std::cout << items[temp] << "\t";
        temp = (temp + 1) % maxQue;
    }
    std::cout << items[temp];
    
    std::cout << " ]" << std::endl;
}
