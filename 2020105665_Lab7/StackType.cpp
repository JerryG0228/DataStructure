//
//  StackType.cpp
//  Lab07
//
//  Modified by Jeman Park on 2023/11/15.
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
    
    while (topPtr != NULL)
    {
        tempPtr = topPtr;
        topPtr = topPtr->next;
        delete tempPtr;
    }
    
}


void StackType::Push(TreeNode* newItem)
{
    if (IsFull()){
        std::cout << "[ERROR] Stack is full. PUSH failed." << std::endl;
    }
    else
    {
        NodeType* newNode;
        newNode = new NodeType;
        newNode->info = newItem;
        newNode->next = topPtr;
        topPtr = newNode;
    }
}


TreeNode* StackType::Pop()
{
    TreeNode* ret;
    if (IsEmpty()){
        std::cout << "[ERROR] Stack is empty. POP failed." << std::endl;
        return NULL;
    }
    else
    {

        NodeType* tempPtr;
        tempPtr = topPtr;
        ret = topPtr->info;
        topPtr = topPtr->next;
        delete tempPtr;
    }
    
    return ret;
}


bool StackType::IsEmpty()
{
    return (topPtr == NULL);
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



void CopyStack(NodeType*& copy, const NodeType* originalStack){
    
    if (originalStack == NULL)
        copy = NULL;
    else
    {
        copy = new NodeType;
        copy->info = originalStack->info;
        CopyStack(copy->next, originalStack->next);
    }
}


void StackType::operator= (const StackType& originalStack){
    if (&originalStack == this){
        return;
    }
    
    this->~StackType();
    CopyStack(topPtr, originalStack.topPtr);
    
}

StackType::StackType(const StackType& anotherStack){
    CopyStack(topPtr, anotherStack.topPtr);
}



void StackType::printStack(){
    NodeType* temp = topPtr;
    std::cout << std::endl;

    std::cout << "STACK: ";
    while (temp != NULL) {
        std::cout << temp->info->info << "\t";
        temp = temp->next;
    }
    std::cout << std::endl;
}
