//
//  PriorityQueType.cpp
//  Lab03-1
//
//  Modified by Jeman Park on 2023/10/03.
//

#include<iostream>
#include "PriorityQueType.h"


PriorityQueType::PriorityQueType(int max)
{
    maxQue = max +1;
    high_front = maxQue -1;
    high_rear = maxQue -1;
    low_front = maxQue -1;
    low_rear = maxQue -1;
    high_items = new ItemType[maxQue];
    low_items = new ItemType[maxQue];
}

PriorityQueType::~PriorityQueType()
{
    delete [] high_items;
    delete [] low_items;
}


bool PriorityQueType::IsEmpty(int priority)
{
    bool result;
    
    /* Implement the function here */
    // Return "if the queue is empty" given the prioirity.
    // Example: input priority == "HIGH"
    // HIGH queue is empty -> return true
    // HIGH queue is not empty -> return false
    
    if (priority == HIGH){
        result = (high_front == high_rear);
    }
    else{
        result = (low_front == low_rear);
    }
    return result;
}

bool PriorityQueType::IsFull(int priority)
{
    bool result;
    
    /* Implement the function here */
    // Return "if the queue is full" given the prioirity.
    // Example: input priority == "HIGH"
    // HIGH queue is full -> return true
    // HIGH queue is not full -> return false
    
    if (priority == HIGH){
        result = ((high_rear + 1) % maxQue == high_front);
    }
    else{
        result = ((low_rear + 1) % maxQue == low_front);
    }
    
    return result;
}

void PriorityQueType::Enqueue(ItemType newItem, int priority)
{
    if (IsFull(priority)){
        if (priority == HIGH){
            std::cout << "[ERROR] HIGH Queue is full. Enqueue failed." << std::endl;
        }
        else{
            std::cout << "[ERROR] LOW Queue is full. Enqueue failed." << std::endl;
        }
        return;
    }
    /* Implement the function here */
    // Enqueue "newItem" into HIGH or LOW queue
    if (priority == HIGH){
        high_rear = (high_rear+1) % maxQue;
        high_items[high_rear] = newItem;
    }
    else{
        low_rear = (low_rear+1) % maxQue;
        low_items[low_rear] = newItem;
    }
}

ItemType PriorityQueType::Dequeue()
{
    if (IsEmpty(HIGH) == true && IsEmpty(LOW) == true){
        std::cout << "[ERROR] Queue is empty. Dequeue failed." << std::endl;
        return -1;
    }
    ItemType item;
    /* Implement the function here */
    // If HIGH queue contains item, return it
    // if HIGH queue is empty, then return from LOW queue.
    
    if (!IsEmpty(HIGH)){
        high_front = (high_front + 1) % maxQue;
        item = high_items[high_front];
    }
    else{
        low_front = (low_front + 1) % maxQue;
        item = low_items[low_front];
    }
    
    return item;
}

void PriorityQueType::printQueue()
{
    // print HIGH queue
    if (IsEmpty(HIGH)){
        std::cout << "HIGH: []" << std::endl;
    }
    else{
        int temp = (high_front + 1) % maxQue;
        
        std::cout << "HIGH: [ ";
        
        while (temp != high_rear){
            std::cout << high_items[temp] << "\t";
            temp = (temp + 1) % maxQue;
        }
        std::cout << high_items[temp];
        
        std::cout << " ]" << std::endl;
    }
    
    // print LOW queue
    if(IsEmpty(LOW)){
        std::cout << "LOW: []" << std::endl;
    }
    else{
        int temp = (low_front + 1) % maxQue;
        
        std::cout << "LOW: [ ";
        
        while (temp != low_rear){
            std::cout << low_items[temp] << "\t";
            temp = (temp + 1) % maxQue;
        }
        std::cout << low_items[temp];
        
        std::cout << " ]" << std::endl;
    }
}
