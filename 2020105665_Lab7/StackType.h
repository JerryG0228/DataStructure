//
//  StackType.h
//  Lab07
//
//  Modified by Jeman Park on 2023/11/15.
//

#include "QueType.h"

#ifndef STACKTYPE_H
#define STACKTYPE_H



class StackType
{
public:
    
    StackType();
    ~StackType();
    StackType(const StackType& anotherStack);
    void operator=(const StackType& originalStack);
    bool IsFull();
    bool IsEmpty();
    void Push(TreeNode* newItem);
    TreeNode* Pop();
    void printStack();
    
private:
    NodeType* topPtr;
};

#endif
