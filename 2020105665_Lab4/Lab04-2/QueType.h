//
//  QueType.h
//  Lab04-2
//
//  Modified by Jeman Park on 2023/10/17.
//

#ifndef QUETYPE_H
#define QUETYPE_H

#include<iostream>

template <class ItemType>
struct NodeType;

template <class ItemType>
class QueType
{
public: 
    QueType();
    ~QueType();
    bool IsEmpty();
    bool IsFull();
    void Enqueue(ItemType newItem);
    void Dequeue(ItemType& item);
    void ReplaceItem(ItemType oldItem, ItemType newItem);
    void printQueue();
private:
    NodeType<ItemType>* front;
    NodeType<ItemType>* rear;
};

template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};


template <class ItemType>
QueType<ItemType>::QueType()
{
    front = NULL;
    rear = NULL;
}


template <class ItemType>
QueType<ItemType>::~QueType()
{
    /* Implement the function here */
    // Deallocate all nodes in the queue.
    // Set Front and Rear pointers properly (NULL).
    NodeType<ItemType>* del;
    while(front == NULL){
        del = front;
        front = front->next;
        delete del;
    }
    
    std::cout << "QUEUE is completely deleted." << std::endl;
}


template<class ItemType>
bool QueType<ItemType>::IsFull()
{
    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

template <class ItemType>
bool QueType<ItemType>::IsEmpty()
{
    /* Implement the function here */
    // Return TRUE if the queue is empty
    // Otherwise, return FALSE

    if(front==NULL) return true;
    else return false;
    
}

template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem)
{
    if (IsFull()){
        std::cout << "[ERROR] Queue is full. Enqueue failed." << std::endl;
        return;
    }

    /* Implement the function here */
    // Insert newItem into the queue (to rear) by creating and linking a new node.

    NodeType<ItemType>* tempPtr = new NodeType<ItemType>;
    tempPtr->info = newItem;
    tempPtr->next = NULL;
    if(rear==NULL) front = tempPtr;
    else rear->next = tempPtr;
    rear = tempPtr;
}


template <class ItemType>
void QueType<ItemType>::Dequeue(ItemType& item)
{
    if (IsEmpty()){
        std::cout << "[ERROR] Queue is empty. Dequeue failed." << std::endl;
        return;
    }
    
    /* Implement the function here */
    // Dequeue the front element of the queue
    // * Return the value of the most front node (call by reference "item")
    // * Delete the dequeued node
    // * Maintain the linked structure correctly
    
    NodeType<ItemType>* tempPtr;
    item = front->info;
    tempPtr = front;
    front = front->next;
    delete tempPtr;
    
}

template <class ItemType>
void QueType<ItemType>::ReplaceItem(ItemType oldItem, ItemType newItem) {
    /* Implement the function here */
    // Replace oldItems in the queue with newItem
    // For example,
    // Queue = (front) 1, 2, 2, 5 (rear)
    // ReplaceItem(2,3)
    // --> Queue = (front) 1, 3, 3, 5 (rear)
    
    NodeType<ItemType>* repPtr = front;
    while(repPtr != rear){
        if(repPtr->info == oldItem) repPtr->info = newItem;
        repPtr = repPtr->next;
    }
    if(repPtr->info == oldItem) repPtr->info = newItem;
}

template <class ItemType>
void QueType<ItemType>::printQueue()
{
    NodeType<ItemType>* location = front;
    std::cout << "(front) [\t";
   
    while (location != NULL) {
        std::cout << location->info << "\t";
        location = location->next;
    }
    
    std::cout << "] (rear)" << std::endl;
}


#endif
