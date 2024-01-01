//
//  StackType.cpp
//  Lab02-2
//
//  Modified by Jeman Park on 2023/09/25.
//

#include "MinQueType.h"
#include <iostream>

QueType::QueType(int max)
{
    maxQue = max + 1;
    front = max;
    rear = max;
    minPos = rear;
    items = new ItemType[maxQue];
}
QueType::~QueType()
{
    delete [] items;
}

bool QueType::IsEmpty() const
{
    return (rear == front);
}

bool QueType::IsFull() const
{
    bool result;
    /* Implement the function here */
    
    // If the queue is not full -> return false
    // If the queue is filled, but it contains more than one "-1" values -> return false
    // If the queue is filled with valid items (> -1) -> return true
    
    if ((rear + 1) % maxQue == front){
        result = true;
        for (int i = (front + 1) % maxQue; i < rear + 1; i++)
        {
            i = i % maxQue;
            if (items[i] == -1) {
                result = false;
            }
        }
    }
    else{
        result = false;
    }
    
    return result;
}

void QueType::Enqueue(ItemType newItem)
{
    if (IsFull()){
        std::cout << "[ERROR] Queue is full. Enqueue failed." << std::endl;
        return;
    }
    
    /* Implement the function here */
    // If the queue has "-1" item, replace it first.
    // else, add the item to the queue
    
    // Example (maxQue == 5):
    // Q = [3, -1, 2] -> Enqueue(4) -> Q = [3, 4, 2]
    // Q = [1, 2] -> Enqueue(3) -> Q = [1, 2, 3]
    // Q = [-1, 2, -1] -> Enqueue(3) -> Q = [3, 2, -1]
    
    if (IsEmpty()) {
        rear = (rear + 1) % maxQue;
        items[rear] = newItem;
        minPos = rear;
    }
    else {
        for (int i = (front + 1) % maxQue; i < rear + 1; i++)
        {
            i = i % maxQue;
            if (items[i] == -1) {
                items[i] = newItem;
                if (newItem < items[minPos])
                    minPos = i;
                return;
            }
        }
        rear = (rear + 1) % maxQue;
        items[rear] = newItem;
        if (newItem < items[minPos])
            minPos = rear;
    }
}

ItemType QueType::MinDequeue()
{
    if (IsEmpty()){
        std::cout << "[ERROR] Queue is empty. Dequeue failed." << std::endl;
        return -1;
    }
    if (items[minPos] == -1){
        std::cout << "[ERROR] Queue is empty (all values == -1). Dequeue failed." << std::endl;
        return -1;
    }
    
    ItemType item;
    /* Implement the function here */
    // 1) return the minimum value
    // 2) set the item dequeued as -1
    // 3) update minPos accordingly.
    // Example: Q=[4,3,8,2,6], minPos = 3 (index of 2)
    // MinDequeue() returns 2 (minimum value)
    // Then Q=[4,3,8,-1,6], minPos = 1 (index of 3)
    
    item = items[minPos];
    items[minPos] = -1;
    
    ItemType min = -1;
    
    for (int i = (front + 1) % maxQue; i < rear + 1; i++)
    {
        i = i % maxQue;
        
        if (items[i] != -1 && min == -1) {
            min = items[i];
            minPos = i;
        }
        
        if (items[i] != -1 && min != -1) {
            if (items[i] < min) {
                min = items[i];
                minPos = i;
            }
        }
        
    }
    return item;
}


void QueType::printQueue()
{
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
