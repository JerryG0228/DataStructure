//
//  StackType.cpp
//  Lab04-1
//
//  Modified by Jeman Park on 2023/10/17.
//

#include <iostream>
#include "StackType.h"


StackType::StackType()
{
    topPtr = NULL;
}


StackType::~StackType()
{
    NodeType* tempPtr;
    
    /* Implement the function here */
    // Deallocate all nodes in the stack.
    while(topPtr!=NULL){
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
    
    
    
    
    std::cout << "STACK is completely deleted." << std::endl;
}


bool StackType::IsEmpty()
{
    /* Implement the function here */
    // Return TRUE if the stack is empty
    // Otherwise, return FALSE
    if(topPtr == NULL) return true;
    else return false;
}


bool StackType::IsFull()
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


void StackType::Push(ItemType newItem)
{
    if (IsFull()){
        std::cout << "[ERROR] Stack is full. PUSH failed." << std::endl;
        return;
    }

    /* Implement the function here */
    // Insert newItem into the stack by creating and linking a new node.
    NodeType* tempPtr = new NodeType;
    tempPtr->info = newItem;
    tempPtr->next = topPtr;
    topPtr = tempPtr;
    
}


ItemType StackType::Pop()
{
    ItemType ret;
    if (IsEmpty()){
        std::cout << "[ERROR] Stack is empty. POP failed." << std::endl;
        return -1;
    }
    /* Implement the function here */
    // Pop the top element of the stack
    // * Return the value of the top node (set "ret")
    // * Delete the popped node
    // * Maintain the linked structure correctly
    NodeType* tempPtr;
    tempPtr = topPtr;
    ret = topPtr->info;
    topPtr = topPtr->next;
    delete tempPtr;


    return ret;
}




void StackType::ReplaceItem(ItemType oldItem, ItemType newItem) {
    /* Implement the function here */
    // Replace oldItems in the stack with newItem
    // For example,
    // Stack = 1, 2, 2, 5 (top)
    // ReplaceItem(2,3)
    // --> Stack = 1, 3, 3, 5 (top)

    NodeType* rep = topPtr;
    while(rep != NULL){
        if(rep->info == oldItem)
            rep->info = newItem;
        rep = rep->next;
    }
    
}

void StackType::printStack(){
    NodeType* location = topPtr;

    std::cout << " (top) ";
    while (location != NULL) {
        std::cout << location->info << "\t";
        location = location->next;
        
    }
    std::cout << "] " << std::endl;
    
}
