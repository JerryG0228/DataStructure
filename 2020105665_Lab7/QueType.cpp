//
//  QueType.cpp
//  Lab07
//
//  Modified by Jeman Park on 2023/11/15.
//

#include <cstddef>
#include <new>
#include <iostream>
#include "QueType.h"

using namespace std;


QueType::QueType(){
    front = NULL;
    rear = NULL;
}
    
QueType::~QueType()
{
    NodeType* tempPtr;
    
    while (front != NULL)
    {
        tempPtr = front;
        front = front->next;
        delete tempPtr;
    }
    rear = NULL;
}


bool QueType::IsFull() const
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc)
    {
        return true;
    }
}


bool QueType::IsEmpty() const{
    return (front == NULL);
}


void QueType::Enqueue(TreeNode* newItem){
    if (IsFull()){
        std::cout << "[ERROR] Queue is full. Enqueue failed." << std::endl;
        return;
    }
    else
    {
        NodeType* newNode;
        
        newNode = new NodeType;
        newNode->info = newItem;
        newNode->next = NULL;
        if (rear == NULL)
            front = newNode;
        else
            rear->next = newNode;
        rear = newNode;
    }
}


TreeNode* QueType::Dequeue(){
    TreeNode* ret;
    if (IsEmpty()){
        std::cout << "[ERROR] Queue is empty. Dequeue failed." << std::endl;
        return NULL;
    }
    else
    {
        NodeType* tempPtr;
        
        tempPtr = front;
        ret = front->info;
        front = front->next;
        if (front == NULL){
            rear = NULL;
        }
        if(tempPtr == NULL){
            delete tempPtr;
        }
    }
    return ret;
}


void CopyQueue(NodeType*& copy, const NodeType* originalQueue){
    
    if (originalQueue == NULL)
        copy = NULL;
    else
    {
        copy = new NodeType;
        copy->info = originalQueue->info;
        CopyQueue(copy->next, originalQueue->next);
    }
}


void QueType::operator= (const QueType& originalQueue){
    if (&originalQueue == this){
        return;
    }
    
    this->~QueType();
    CopyQueue(front, originalQueue.front);
    
}

QueType::QueType(const QueType& anotherQue){
    CopyQueue(front, anotherQue.front);
}


void QueType::printQueue(){
    NodeType* temp = front;
    cout << "QUEUE: ";
    while(temp != NULL){
        cout << temp->info->info << "\t";
        temp = temp->next;
    }
    cout << endl;
    
}
