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
    /* Implement the function here */
    
    // If the queue is not full -> return false
    // If the queue is filled, but it contains more than one "-1" values -> return false
    // If the queue is filled with valid items (> -1) -> return true
    if((rear + 1) % maxQue != front) return false;
    else{
        if(front > rear){
            for(int i = front+1;i<maxQue;i++){
                if(items[i]==-1) return false;
            }
            for(int i = 0;i<=rear;i++){
                if(items[i]==-1) return false;
            }
        }else{
            for(int i=front+1;i<=rear;i++){
                if(items[i]==-1) return false;
            }
        }
        return true;
    }
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
    bool find = false;
    if(IsEmpty()){
        rear = 0;
        minPos = 0;
        items[rear] = newItem;
    }else{
        if(front > rear){
            for(int i = front+1;i<maxQue;i++){
                if(find) break;
                if(items[i]==-1){
                    items[i] = newItem;
                    find=true;
                }
            }
            for(int i = 0;i<=rear;i++){
                if(find) break;
                if(items[i]==-1){
                    items[i] = newItem;
                    find=true;
                }
            }
        }else{
            for(int i=front+1;i<=rear;i++){
                if(find) break;
                if(items[i]==-1){
                    find=true;
                }
            }
        }

        if(!find){
            if(rear == maxQue-1) rear=0;
            else rear++;
            items[rear] = newItem;
        }
        for(int i =0; i<maxQue;i++){
        if(items[i]>0) minPos = i;
        }
        for(int i =0; i<maxQue;i++){
            if(items[i]>0){
            if(items[i]<items[minPos]) minPos=i;
            }
        }
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

    for(int i =0; i<maxQue;i++){
        if(items[i]>0) minPos = i;
    }
    for(int i =0; i<maxQue;i++){
        if(items[i]>0){
            if(items[i]<items[minPos]) minPos=i;
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
